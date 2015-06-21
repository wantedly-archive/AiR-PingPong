# AiR-PingPong

Wantedlyの卓球台をARでハックするプロジェクト

## Getting Started

1. このリポジトリをクローンする
2. `open of_v0.8.4_osx_release/apps/myApps/pinpong/pinpong.xcodeproj`でXcodeのプロジェクトを開く
3. スタートボタンを押してビルドできることを祈る

簡単のため、リポジトリ内に[Open Frameworks](http://openframeworks.jp/)は全てすでに取り込んであるのでダウンロードしなくて大丈夫です。

## How to add new project

1. プロジェクトジェネレータを開く`open of_v0.8.4_osx_release/projectGenerator_osx/projectGenerator.app`
2. プロジェクトの名前とPath(`myApps`以下推奨)を選ぶ
3. ofxOpenCv, ofxMSAInteractiveObject, ofxQuadWrapを選ぶ
4. `GENERETE PROJECT`ボタンを押す

moguraを作った時の例:
![moguraを作った時の例](/doc/img/ProjectGenerator.png)

後は、`ofApp.cpp`, `ofApp.h`, `main.cpp`のどれかからいじっていくと良い

## Chat

リアルタイムコミュニケーションは以下のGitterを使っています。

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/wantedly/AiR-PingPong?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
