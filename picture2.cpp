#include<opencv2/opencv.hpp>
#include<vector>
using namespace cv;
using namespace std;
#pragma comment(lib,"opencv_world451.lib")

int main()
{
    CascadeClassifier cascade;
    cascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml"); //���ʊ��񂪓����Ă���J�X�P�[�h�t�@�C���ǂݍ���
    Mat img = imread("2.jpg"); //���͉摜�ǂݍ���
    if (img.empty() == true)
    {
        return 0;  // �摜�f�[�^���ǂݍ��߂Ȃ������Ƃ��ɏI��������
    }
    Mat gray_img;
    cvtColor(img, gray_img, COLOR_BGR2GRAY); //�����摜�ɂ��邱�Ƃŏ������y������
    vector<Rect> face; //�֊s���̊i�[�ꏊ
    cascade.detectMultiScale(img, face, 1.01, 7, 2, Size(10, 10), Size(40, 35)); //�J�X�P�[�h�t�@�C���Ɋ�Â��Ċ�����m����D���m����������x�N�g��faces�Ɋi�[

    for (int i = 0; i < face.size(); i++) //���o������̌�"faces.size()"�����[�v���s��
    {
        rectangle(img, Point(face[i].x, face[i].y), Point(face[i].x + face[i].width, face[i].y + face[i].height), Scalar(0, 0, 255), 3, LINE_AA); //���o�������ԐF��`�ň͂�
    }
   
    cout << "�摜�Ɏʂ��Ă���l��" << face.size() << "�l�ł�" << endl;
    imwrite("picture2.jpg", img);
    imshow("detect face", img);
    waitKey(0);

}

