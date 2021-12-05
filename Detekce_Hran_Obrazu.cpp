//import knihoven opencv a iostream
#include <opencv2/opencv.hpp> 
#include <iostream> 

//deklarujeme pro zjednodušení psaní příkazů z dané knihovny cv::fce(), std::fce()
using namespace std;
using namespace cv; 

//deklarace promennych pro metodu Canny Edge Detection
int minVal = 0;
int max_minVal = 100;
int pomer = 3; //pomer max_threshold:min_threshold (3:1)
int kernel_velikost = 3;

Mat img, img_gray, img_blur, edges, sobelx, sobely, sobelxy;


void CannyThreshold(int, void*) 
{

    GaussianBlur(img_gray,
        img_blur,
        Size(3, 3),
        0); //míra rozmazání obrazu

    Canny(img_blur,
        edges,
        minVal, //spodní prahová hranice
        minVal*pomer,//horní prahová hranice
        kernel_velikost,
        false);           

    imshow("Edge Detection", edges);
}

int main()
{    //načtení obrázku z adresáře skriptu
    img = imread("test6.jpg");
    if (img.empty())
    {
        cout << "Soubor nebyl nalezen!" << endl;
        return -1;
    }

    //převedení na černobílé spektrum
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    
    //implementace Gaussovského vyhlazování
    GaussianBlur(img_gray, img_blur, Size(3, 3), 0);

    //porovnání obrázku před a po aplikaci Gussovského vyhlazování
    imshow("Původní obrázek černobíle", img_gray);
    imshow("Gaussovo vyhlazování", img_blur);
    waitKey(0);

    //detekce hran pomocí Sobelovy metody
    Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);
    Sobel(img_blur, sobely, CV_64F, 0, 1, 5);
    Sobel(img_blur, sobelxy, CV_8U, 1, 1, 5);

    //zobrazení obrázku pomocí Sobelovy metody
    imshow("Sobel ve směru X", sobelx);
    imshow("Sobel ve směru Y", sobely);
    imshow("Sobel kombinace XY", sobelxy);
    waitKey(0);

    // zobrazení původního obrázku
    imshow("Původní obrázek", img);

    //aplikace canny edge detection algoritmu
    namedWindow("Edge Detection", WINDOW_AUTOSIZE);
    // Canny Edge Detector
    createTrackbar("Min_Val:", "Edge Detection", &minVal, max_minVal, CannyThreshold);
    CannyThreshold(0, 0);

   
    //uložení obrázku s detekovanými hranami do adresáře skriptu
    //imwrite("test7_detekce_hran.jpg", edges);
    //zobrazení canny edge detected obrázku
    //imshow("Detekce hran v obrazu pomocí Canny edge detection", edges);
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
