
//
// OpenSiv3D v0.4.2 ゲームテンプレート
//

//
// macOS では README.md と同じフォルダに
// include と lib をコピーしてください。
//

# include "Common.hpp"
# include "Title.hpp"
# include "Game.hpp"

void Main()
{
    /* -- 初期設定 -- */
    const Texture texture(U"swordEffect.png");  // テクスチャのパス
    const Size size(192, 192);                  // 1コマのサイズ
    const double rate = 0.08;                   // 次のコマへの切り替え時間    
    const int32 maxCount = 12;                  // 全コマ数
    const int32 xNum = 5;                       // 横のコマ数
    const int32 yNum = 3;                       // 縦のコマ数

    /* -- 以下処理 -- */
    int32 count = 0;
    int32 posX = 0;
    int32 posY = 0;
    double accum = 0;
    bool isComplete = false;

    Scene::SetBackground(Palette::White);
    if (!texture)
        throw Error(U"Not found Texture!");

    while (System::Update())
    {
        accum += Scene::DeltaTime();
        if (isComplete) {
            accum = 0;
            isComplete = false;
        }

        if (accum >= rate) {
            ++count;
            accum = 0;
            ++posX;
            if (count % xNum == xNum - 1) {
                ++posY;
                posX = 0;
            }

            if (maxCount <= count) {
                count = 0;
                posX = 0;
                posY = 0;
                isComplete = true;
                System::Sleep(1000);
            }
        }

        texture(size.x * posX, size.y * posY, size).drawAt(Scene::Center());
    }
}

//
// = クロスプラットフォーム開発の注意 =
//
// Xcode でソースコードを保存すると UTF-8 形式 (BOM 無し) になります。
// MSVC で作業するときはソースコードを UTF-8 (BOM 付き) に直す必要があります。
//
//
// = アドバイス =
// macOS 10.15 Catalina の Xcode プロジェクトで、
// ビルドしたプログラムを起動するたびにファイルアクセス許可のダイアログが表示される場合、
// プロジェクトのフォルダを User/アプリケーション に移動させることで通常は表示されなくなります。
// 特別なファイルシステム関数の使用や、Web カメラ、マイク使用時のダイアログまでは消せません。
//
//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// 質問などのサポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D Slack (ユーザコミュニティ) への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
