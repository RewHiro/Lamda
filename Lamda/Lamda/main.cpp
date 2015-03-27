#include <iostream>

//　ラムダ式(無名関数)

int main(){

	{
		//　ラムダ式の基本構造
		//[キャプチャ](仮引数)->戻り値の型{関数の中身}
		//　autoで定義しているのは関数ポインタを使っているので省略します。
		//　MEMO:関数オブジェクトとも関係がある？(調査)
		auto a = ([]()->int{return 10; });
		std::cout << "ラムダ式の基本構造" << std::endl;
		std::cout << a() << "\n" << std::endl;
	}

	{
		//　->戻り値の型は省略できます。
		//　()仮引数も省略できます。
		auto a = []{return 20; };
		std::cout << "省略" << std::endl;
		std::cout << a() << "\n" << std::endl;
	}

	{
		//　仮引数の利用
		auto a = [](int n){return n * n; };
		std::cout << "仮引数の利用" << std::endl;
		std::cout << a(5) << "\n" << std::endl;
	}
	{
		//　コピーキャプチャ
		int b = 2;
		auto a = [=](int n){return b + n; };
		std::cout << "コピーキャプチャ" << std::endl;
		std::cout << a(5) << "\n" << std::endl;
	}
	{
		//　参照キャプチャ
		int b = 2;
		std::cout << "参照キャプチャ" << std::endl;
		std::cout << b << std::endl;
		auto a = [&](int n){
			b = n;
			return b;
		};
		std::cout << a(5) << "\n" << std::endl;
	}

	//　コピーと参照の理解は
	//　void (int a,int b)->コピー
	//　void (int& a,int& b)->参照
	//　こんな感じ！


	//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
	//　補足
	//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

	//　キャプチャリストは[a,&a,]
	//　の様に複数指定、変数指定できる！

	{
		//　ラムダ式をすぐ実行したいときは}の後ろに()をつける
		//　[]{}->が関数名みたいなもの
		int a = []{return 10; }();
		std::cout << "補足" << std::endl;
		std::cout << a << std::endl;
	}

	//　型推論の正体
	//　auto a = int(*a)()
	//　auto a = int(*a)(int n)

	//　どこでラムダ式を使うか
	//　関数名がかさなりそうなときや関数ポインタを使いたいときに利用！

}

//　例
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

// ↓↓↓

//void Create(int type){
	//	std::shared_prt<Scene> scene;
	//	switch(type){
	//	case 1:　　　
	//		scene = []{return std::make_shared<Title>();}();
	//		break;
	//	case 2:
	//		scene = []{return std::make_shared<Stage>();}();
	//		break;
	//	}
//}

//　記述が減るのでいい！