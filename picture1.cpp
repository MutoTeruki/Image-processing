#include<opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
#pragma comment(lib, "opencv_world451.lib")

int main()
{
    CascadeClassifier cascade;
    cascade.load("C:\\Program Files\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"); //正面顔情報が入っているカスケードファイル読み込み
    Mat img = imread("1.jpg"); //入力画像読み込み
    Mat gray_img;
    if (img.empty()  == true) 
    {
        return 0;  // 画像データが読み込めなかったときに終了させる
    }
    vector<Rect> face; //輪郭情報の格納場所
    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    cascade.detectMultiScale(gray_img, face, 1.1, 3, 0, Size(100, 100)); //カスケードファイルに基づいて顔を検知する．検知した顔情報をベクトルfacesに格納.各種パラメータは状況に応じて変化させる

    for (int i = 0; i < face.size(); i++) //検出した顔の個数"faces.size()"分ループを行う
    {
        rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //検出した顔を赤色矩形で囲む
    }

    imshow("detect face", img);
    cout << "画像に写っている人は" << face.size() << "人です" << endl;
    
    imwrite("picture1.jpg", img);
    
    waitKey(0);
}
