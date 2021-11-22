//import knihoven opencv a iostream
#include <opencv2/opencv.hpp> 
#include <iostream> 

//deklarujeme pro zjednodušení psaní příkazů z dané knihovny cv::fce(), std::fce()
using namespace std;
using namespace cv; 

int main()
{    //načtení obrázku z adresáře skriptu
    Mat img = imread("test7.jpg");

    //převedení na černobílé spektrum
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    
    //implementace Gaussovského vyhlazování
    Mat img_blur;
    GaussianBlur(img_gray, img_blur, Size(3, 3), 0);

    //porovnání obrázku před a po aplikaci Gussovského vyhlazování
    imshow("Původní obrázek černobíle", img_gray);
    imshow("Gaussovo vyhlazování", img_blur);
    waitKey(0);

    //detekce hran pomocí Sobelovy metody
    Mat sobelx, sobely, sobelxy;
    Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);
    Sobel(img_blur, sobely, CV_64F, 0, 1, 5);
    Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);

    //zobrazení obrázku pomocí Sobelovy metody
    imshow("Sobel ve směru X", sobelx);
    imshow("Sobel ve směru Y", sobely);
    imshow("Sobel kombinace XY", sobelxy);
    waitKey(0);

    //aplikace canny edge detection algoritmu
    Mat edges;
    Canny(img_blur, edges, 100, 200, 3, false);


    // zobrazení původního obrázku
    imshow("Původní obrázek", img);    
    //uložení obrázku s detekovanými hranami do adresáře skriptu
    imwrite("test7_detekce_hran.jpg", edges);
    //zobrazení canny edge detected obrázku
    imshow("Detekce hran v obrazu pomocí Canny edge detection", edges);
    waitKey(0);
    destroyAllWindows();
    return 0;
}


// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
