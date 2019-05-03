#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 60fps感覚でupdateとdrawを行う
    ofSetFrameRate(60);
    // 垂直同期→フレーム数と実際の描画枚数を同期させるか
    ofSetVerticalSync(true);
    // 円の解像度設定
    ofSetCircleResolution(32);
    // 混色法の設定
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0, 0, 0);
    
    // FFTの周波数成分の解像度うを設定（2の累乗）
    nBandsToGet = 1024;
    
    mySound.load("EDM_Tr1_P_B.mp3");
    mySound.setLoop(true);
    // サウンドファイルを読み込んでループ再生
    mySound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    // サウンドプレイヤーを更新して、FFT解析
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(nBandsToGet);
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 円の配置間隔を計算
    float width = float(ofGetWidth()) / float(nBandsToGet) / 2.0f;
    
    for (int i=0; i < nBandsToGet; i++) {
        // 色のグラデーションを生成
        int b = float(255) / float(nBandsToGet) * i;
        int g = 31;
        int r = 255 - b;
        ofSetColor(r, g, b);
        // 円の描画
        ofDrawCircle(ofGetWidth()/2 + width * i, ofGetHeight()/2, fft[i] * 800);
        ofDrawCircle(ofGetWidth()/2 + width * i, ofGetHeight()/2, fft[i] * 800);
    }
}
