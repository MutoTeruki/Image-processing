#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;
#pragma comment(lib,"opencv_world451.lib")

int main()
{
    CascadeClassifier cascade;
    Mat img = imread("3.jpg"); //���͉摜�ǂݍ���
    Mat gray_img;
    if (img.empty() == true)
    {
        return 0;  // �摜�f�[�^���ǂݍ��߂Ȃ������Ƃ��ɏI��������
    }
    cvtColor(img, gray_img, COLOR_BGR2GRAY);//�����摜�ɂ��ď������y������
    //���E�ŕʁX�̃J�X�P�[�h�t�@�C����p���ĉ摜���o�𐳊m�ɍs��

    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");
    vector<Rect> face; //�֊s���̊i�[�ꏊ
    cascade.detectMultiScale(gray_img, face, 1.1, 2, 0, Size(150, 150), Size(500, 500)); //�J�X�P�[�h�t�@�C���Ɋ�Â��Ċ�����m����D���m����������x�N�g��faces�Ɋi�[
    int l = 0;
    for (int i = 0; i < face.size(); i++) //���o������̌�"faces.size()"�����[�v���s��
    {
        if (face[i].x < 1200 && face[i].y < 2200)//�����̐l���������o
        {
            l++;
            rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //���o�������ԐF��`�ň͂�
        }
        
    }

    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_profileface.xml");
    vector<Rect> profile; //�֊s���̊i�[�ꏊ
    cascade.detectMultiScale(gray_img, profile, 1.01, 0, 0, Size(200, 200), Size(500, 500)); //�J�X�P�[�h�t�@�C���Ɋ�Â��Ċ�����m����D���m����������x�N�g��faces�Ɋi�[
    int k = 0;
    for (int j = 0; j < profile.size(); j++) //���o������̌�"faces.size()"�����[�v���s��
    {
        if (profile[j].x > 1950 && profile[j].y > 1000 && profile[j].y < 2000)//�E���̐l���������o
        {
            k++;
            rectangle(img, Point(profile[j].x, profile[j].y), Point(profile[j].x + profile[j].width, profile[j].y + profile[j].height), Scalar(0, 0, 255), 3, LINE_AA); //���o�������ԐF��`�ň͂�
        }

    }
    imwrite("picture3.jpg", img);
    resize(img, img, Size(), 0.2, 0.2);

    imshow("detect face", img);
    cout << "�摜�Ɏʂ��Ă���l��" << l + k << "�l�ł�" << endl;
    waitKey(0);


}