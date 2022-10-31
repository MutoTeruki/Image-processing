#include<opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
#pragma comment(lib, "opencv_world451.lib")

int main()
{
    CascadeClassifier cascade;
    cascade.load("C:\\Program Files\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"); //���ʊ��񂪓����Ă���J�X�P�[�h�t�@�C���ǂݍ���
    Mat img = imread("1.jpg"); //���͉摜�ǂݍ���
    Mat gray_img;
    if (img.empty()  == true) 
    {
        return 0;  // �摜�f�[�^���ǂݍ��߂Ȃ������Ƃ��ɏI��������
    }
    vector<Rect> face; //�֊s���̊i�[�ꏊ
    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    cascade.detectMultiScale(gray_img, face, 1.1, 3, 0, Size(100, 100)); //�J�X�P�[�h�t�@�C���Ɋ�Â��Ċ�����m����D���m����������x�N�g��faces�Ɋi�[.�e��p�����[�^�͏󋵂ɉ����ĕω�������

    for (int i = 0; i < face.size(); i++) //���o������̌�"faces.size()"�����[�v���s��
    {
        rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //���o�������ԐF��`�ň͂�
    }

    imshow("detect face", img);
    cout << "�摜�Ɏʂ��Ă���l��" << face.size() << "�l�ł�" << endl;
    
    imwrite("picture1.jpg", img);
    
    waitKey(0);
}
