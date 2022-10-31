#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;
#pragma comment(lib,"opencv_world451.lib")

int main()
{
    CascadeClassifier cascade;
    Mat img = imread("3.jpg"); //入力画像読み込み
    Mat gray_img;
    if (img.empty() == true)
    {
        return 0;  // 画像データが読み込めなかったときに終了させる
    }
    cvtColor(img, gray_img, COLOR_BGR2GRAY);//白黒画像にして処理を軽くする
    //左右で別々のカスケードファイルを用いて画像検出を正確に行う

    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");
    vector<Rect> face; //輪郭情報の格納場所
    cascade.detectMultiScale(gray_img, face, 1.1, 2, 0, Size(150, 150), Size(500, 500)); //カスケードファイルに基づいて顔を検知する．検知した顔情報をベクトルfacesに格納
    int l = 0;
    for (int i = 0; i < face.size(); i++) //検出した顔の個数"faces.size()"分ループを行う
    {
        if (face[i].x < 1200 && face[i].y < 2200)//左側の人物だけ検出
        {
            l++;
            rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //検出した顔を赤色矩形で囲む
        }
        
    }

    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_profileface.xml");
    vector<Rect> profile; //輪郭情報の格納場所
    cascade.detectMultiScale(gray_img, profile, 1.01, 0, 0, Size(200, 200), Size(500, 500)); //カスケードファイルに基づいて顔を検知する．検知した顔情報をベクトルfacesに格納
    int k = 0;
    for (int j = 0; j < profile.size(); j++) //検出した顔の個数"faces.size()"分ループを行う
    {
        if (profile[j].x > 1950 && profile[j].y > 1000 && profile[j].y < 2000)//右側の人物だけ検出
        {
            k++;
            rectangle(img, Point(profile[j].x, profile[j].y), Point(profile[j].x + profile[j].width, profile[j].y + profile[j].height), Scalar(0, 0, 255), 3, LINE_AA); //検出した顔を赤色矩形で囲む
        }

    }
    imwrite("picture3.jpg", img);
    resize(img, img, Size(), 0.2, 0.2);

    imshow("detect face", img);
    cout << "画像に写っている人は" << l + k << "人です" << endl;
    waitKey(0);


}