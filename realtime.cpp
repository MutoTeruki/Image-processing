#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

using namespace cv;
using namespace std;
#pragma comment(lib,"opencv_world451.lib")

int main()
{
    Mat frame; //USBカメラから得た１フレームを格納する場所
    CascadeClassifier cascade;
    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml"); //正面顔情報が入っているカスケード
    vector<Rect> faces; //輪郭情報を格納場所

    VideoCapture cap(0); // カメラを開く
    if (!cap.isOpened()) //カメラが起動できなかった時はプログラム終了
    {
        return -1;
    }

    while (1)//無限ループ
    {
        cap >> frame; //USBカメラが得た動画の１フレームを格納
        cascade.detectMultiScale(frame, faces, 1.1, 3, 0, Size(20, 20)); //格納されたフレームに対してカスケードファイルに基づいて顔を検知
        for (int i = 0; i < faces.size(); i++) //検出した顔の個数"faces.size()"分ループを行う
        {
            rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, COLOR_HSV2BGR); //検出した顔を赤色矩形で囲む
        }

        imshow("window", frame);//画像を表示．

        int key = waitKey(1);
        if (key == 113)//qボタンが押されたとき
        {
            break;//whileループから抜ける（終了）
        }
    }
    destroyAllWindows();
    return 0;
}
