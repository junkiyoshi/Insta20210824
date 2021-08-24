#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int radius = 80;
	int location_radius = 230;
	int deg_span = 60;

	for (int deg = 0; deg < 360; deg += 10) {

		int tmp_deg = deg + ofGetFrameNum() * 0.5;
		vector<glm::vec2> vertices;
		for (int location_deg = 0; location_deg < 360; location_deg += deg_span) {

			auto base_location = glm::vec2(location_radius * cos(location_deg * DEG_TO_RAD), location_radius * sin(location_deg * DEG_TO_RAD));
			auto location = glm::vec2(radius * cos(tmp_deg * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD));

			vertices.push_back(base_location + location);
			tmp_deg += 120;
		}

		ofColor color = ofColor();
		color.setHsb(ofMap(deg, 0, 360, 0, 255), 255, 230);
		ofSetColor(color);

		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		ofFill();
		for (auto vertex : vertices) {

			ofDrawCircle(vertex, 3.5);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}