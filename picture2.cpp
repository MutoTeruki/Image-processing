#include<opencv2/opencv.hpp>
#include<vector>
using namespace cv;
using namespace std;
#pragma comment(lib,"opencv_world451.lib")

int main()
{
    CascadeClassifier cascade;
    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml"); //正面顔情報が入っているカスケードファイル読み込み
    Mat img = imread("2.jpg"); //入力画像読み込み
    if (img.empty() == true)
    {
        return 0;  // 画像データが読み込めなかったときに終了させる
    }
    Mat gray_img;
    cvtColor(img, gray_img, COLOR_BGR2GRAY); //白黒画像にすることで処理を軽くする
    vector<Rect> face; //輪郭情報の格納場所
    cascade.detectMultiScale(img, face, 1.01, 7, 2, Size(10, 10), Size(40, 35)); //カスケードファイルに基づいて顔を検知する．検知した顔情報をベクトルfacesに格納

    for (int i = 0; i < face.size(); i++) //検出した顔の個数"faces.size()"分ループを行う
    {
        rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //検出した顔を赤色矩形で囲む
    }
   
    cout << "画像に写っている人は" << face.size() << "人です" << endl;
    imwrite("picture2.jpg", img);
    imshow("detect face", img);
    waitKey(0);

}

