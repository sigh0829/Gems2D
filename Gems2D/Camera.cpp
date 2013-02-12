#include "stdafx.h"
#include "Camera.h"
#include <iostream>
using namespace std;

Camera::Camera(void) { }

Camera::~Camera(void) { }

void Camera::setWindowSize(int width, int height) {
	m_window_width = width;
	m_window_height = height;
	m_obs_x = width/2;
	m_obs_y = height/2;
}

void Camera::setLevelSize(int width, int height) {
	m_map_width = width;
	m_map_height = height;
}

pair<int, int> Camera::getWindowSize() {
	pair<int, int> p;
	p.first = m_window_width;
	p.second = m_window_height;
	return p;
}

pair<int, int> Camera::getLevelSize() {
	pair<int, int> p;
	p.first = m_map_width;
	p.second = m_map_height;
	return p;
}

pair<int, int> Camera::getObsPoint() {
	pair<int, int> p;
	p.first = m_obs_x;
	p.second = m_obs_y;
	return p;
}

void Camera::getDrawableArea(vector<int>& v) {
	vector<int> drawable (4, 0);
	drawable[0] = m_obs_x - m_window_width/2;
	drawable[1] = m_obs_y - m_window_height/2;
	drawable[2] = m_obs_x + m_window_width/2;
	drawable[3] = m_obs_y + m_window_height/2;
	v = drawable;
}

void Camera::updateCameraPos (int player_x, int player_y) {
	if(player_x - m_obs_x > m_window_width/4) m_obs_x += (player_x - m_obs_x - m_window_width/4);
	if(player_x - m_obs_x < -m_window_width/4) m_obs_x += (player_x - m_obs_x + m_window_width/4);
	if(player_y - m_obs_y > m_window_height/4) m_obs_y += (player_y - m_obs_y - m_window_height/4);
	if(player_y - m_obs_y < -m_window_height/4) m_obs_y += (player_y - m_obs_y + m_window_height/4);
}
