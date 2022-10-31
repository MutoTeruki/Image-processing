#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#pragma comment(lib,"opencv_world451.lib")

int main()
{
    Mat img = imread("4.png", 1);
    if (img.empty() == true)
    {
        return 0;
    }

    HOGDescriptor hog;
    Mat gray_img;
    vector<Rect> found;

    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    hog.detectMultiScale(gray_img, found, 0, Size(6, 9), Size(10, 18), 1.05, 3);//検出サイズを絞ることで集合写真に写っている人の数を正確に検出する



    for (int i = 0; i < found.size(); i++) {
        Rect r = found[i];
        rectangle(img, r.tl(), r.br(), Scalar(0, 255, 0), 2);
    }

    CascadeClassifier cascade;
    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml"); //正面顔情報が入っているカスケードファイル読み込み
    vector<Rect> face; //輪郭情報を格納場所
    cascade.detectMultiScale(img, face, 1.02, 7, 2, Size(180, 180)); //カスケードファイルに基づいて顔を検知する．検知した顔情報をベクトルfacesに格納

    for (int i = 0; i < face.size(); i++) //検出した顔の個数"faces.size()"分ループを行う
    {
        rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //検出した顔を赤色矩形で囲む
    }

    resize(img, img, Size(), 0.5, 0.5);
    cout << "画像に写っている人は" << face.size() + found.size() << "人です" << endl;
    imshow("detect face", img);
    imwrite("picture4.png", img);
    waitKey(0);

}