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
    hog.detectMultiScale(gray_img, found, 0, Size(6, 9), Size(10, 18), 1.05, 3);//���o�T�C�Y���i�邱�ƂŏW���ʐ^�Ɏʂ��Ă���l�̐��𐳊m�Ɍ��o����



    for (int i = 0; i < found.size(); i++) {
        Rect r = found[i];
        rectangle(img, r.tl(), r.br(), Scalar(0, 255, 0), 2);
    }

    CascadeClassifier cascade;
    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml"); //���ʊ��񂪓����Ă���J�X�P�[�h�t�@�C���ǂݍ���
    vector<Rect> face; //�֊s�����i�[�ꏊ
    cascade.detectMultiScale(img, face, 1.02, 7, 2, Size(180, 180)); //�J�X�P�[�h�t�@�C���Ɋ�Â��Ċ�����m����D���m����������x�N�g��faces�Ɋi�[

    for (int i = 0; i < face.size(); i++) //���o������̌�"faces.size()"�����[�v���s��
    {
        rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //���o�������ԐF��`�ň͂�
    }

    resize(img, img, Size(), 0.5, 0.5);
    cout << "�摜�Ɏʂ��Ă���l��" << face.size() + found.size() << "�l�ł�" << endl;
    imshow("detect face", img);
    imwrite("picture4.png", img);
    waitKey(0);

}