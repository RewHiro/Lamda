#include <iostream>

//�@�����_��(�����֐�)

int main(){

	{
		//�@�����_���̊�{�\��
		//[�L���v�`��](������)->�߂�l�̌^{�֐��̒��g}
		//�@auto�Œ�`���Ă���̂͊֐��|�C���^���g���Ă���̂ŏȗ����܂��B
		//�@MEMO:�֐��I�u�W�F�N�g�Ƃ��֌W������H(����)
		auto a = ([]()->int{return 10; });
		std::cout << "�����_���̊�{�\��" << std::endl;
		std::cout << a() << "\n" << std::endl;
	}

	{
		//�@->�߂�l�̌^�͏ȗ��ł��܂��B
		//�@()���������ȗ��ł��܂��B
		auto a = []{return 20; };
		std::cout << "�ȗ�" << std::endl;
		std::cout << a() << "\n" << std::endl;
	}

	{
		//�@�������̗��p
		auto a = [](int n){return n * n; };
		std::cout << "�������̗��p" << std::endl;
		std::cout << a(5) << "\n" << std::endl;
	}
	{
		//�@�R�s�[�L���v�`��
		int b = 2;
		auto a = [=](int n){return b + n; };
		std::cout << "�R�s�[�L���v�`��" << std::endl;
		std::cout << a(5) << "\n" << std::endl;
	}
	{
		//�@�Q�ƃL���v�`��
		int b = 2;
		std::cout << "�Q�ƃL���v�`��" << std::endl;
		std::cout << b << std::endl;
		auto a = [&](int n){
			b = n;
			return b;
		};
		std::cout << a(5) << "\n" << std::endl;
	}

	//�@�R�s�[�ƎQ�Ƃ̗�����
	//�@void (int a,int b)->�R�s�[
	//�@void (int& a,int& b)->�Q��
	//�@����Ȋ����I


	//��������������������������������������������������������������������������������������������
	//�@�⑫
	//��������������������������������������������������������������������������������������������

	//�@�L���v�`�����X�g��[a,&a,]
	//�@�̗l�ɕ����w��A�ϐ��w��ł���I

	{
		//�@�����_�����������s�������Ƃ���}�̌���()������
		//�@[]{}->���֐����݂����Ȃ���
		int a = []{return 10; }();
		std::cout << "�⑫" << std::endl;
		std::cout << a << std::endl;
	}

	//�@�^���_�̐���
	//�@auto a = int(*a)()
	//�@auto a = int(*a)(int n)

	//�@�ǂ��Ń����_�����g����
	//�@�֐����������Ȃ肻���ȂƂ���֐��|�C���^���g�������Ƃ��ɗ��p�I

}

//�@��
//void Create(int type){
//	std::shared_prt<Scene> scene;
//	switch(type){
//	case 1:
//		scene = TitleCreate();
//		break;
//	case 2:
//		scene = StageCreate();
//		break;
//	}
//}
//std::shared_ptr<Scene> TitleCreate(){
//	return std::make_shared<Title>();
//}
//std::shared_ptr<Scene> StageCreate(){
//	return std::make_shared<Stage>();
//}

// ������

//void Create(int type){
	//	std::shared_prt<Scene> scene;
	//	switch(type){
	//	case 1:�@�@�@
	//		scene = []{return std::make_shared<Title>();}();
	//		break;
	//	case 2:
	//		scene = []{return std::make_shared<Stage>();}();
	//		break;
	//	}
//}

//�@�L�q������̂ł����I