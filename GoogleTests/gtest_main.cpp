#include <cstdio>
#include <iostream>
#include <ctime>
#include "BigInteger.h"
#include "gtest/gtest.h"


#ifdef _GTEST
GTEST_API_ int main(int argc, char **argv) 
{
	printf("Running main() from gtest_main.cc\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#else
int main()
{
	clock_t tempoiniziale, tempofinale;
	tempoiniziale = clock();

	BigInteger testpow("12");
	testpow.pow(100);

	BigInteger testInc(10);
	testInc = 200;
	std::cout << "Stato iniziale  : " << testInc << std::endl;
	std::cout << "Post incremento : " << testInc++ << std::endl;
	std::cout << "Stato attuale   : " << testInc << std::endl;
	std::cout << "Pre incremento  : " << ++testInc << std::endl;
	std::cout << "Stato finale    : " << testInc << std::endl;

	std::cout << std::endl << "** test operazioni con segno ***" << std::endl;
	{
		BigInteger neg("-10");
		BigInteger pos("10");
		std::cout << neg << "/" << pos << "=";
		std::cout << neg / pos << std::endl;

		std::cout << neg << "*" << pos << "=";
		std::cout << neg * pos << std::endl;

		std::cout << neg << "*" << neg << "=";
		std::cout << neg * neg << std::endl;

		std::cout << neg << "+" << pos << "=";
		std::cout << neg + pos << std::endl;

		std::cout << neg << "-" << pos << "=";
		std::cout << neg - pos << std::endl;
	}
	{
		BigInteger neg("-50");
		BigInteger pos("100");

		std::cout << neg << "*" << pos << "=";
		std::cout << neg * pos << std::endl;

		std::cout << neg << "*" << neg << "=";
		std::cout << neg * neg << std::endl;

		std::cout << neg << "+" << pos << "=";
		std::cout << neg + pos << std::endl;

		std::cout << neg << "-" << pos << "=";
		std::cout << neg - pos << std::endl;
	}

	std::cout << std::endl << "**test potenza e moltiplicazione** " << std::endl;
	BigInteger asd(1000000);
	std::cout << asd << std::endl;
	std::cout << "per 2              :" << asd * 2 << std::endl;
	std::cout << "somma con se stesso:" << asd + asd << std::endl;
	std::cout << "per se stesso	   :" << asd * asd << std::endl;
	asd.pow(2);
	std::cout << "^2                 :" << asd << std::endl;

	std::cout << std::endl << "**test divisione** " << std::endl;
	BigInteger dividendo("2287342482348930009991239876012345566");
	std::cout << dividendo << "/";
	BigInteger divisore("10000000900001010203000");
	std::cout << divisore << "=" << std::endl;
	BigInteger ris_atteso("228734227648789");   //ris potenzialmente corretto
	std::cout << "risultato atteso    :" << ris_atteso << std::endl;
	BigInteger result = dividendo / divisore;
	std::cout << "risultato calcolato :" << result << std::endl;
	result *= divisore;
	std::cout << "test risultato * divisore  :" << result << std::endl;
	std::cout << "dividendo originale        :" << dividendo << std::endl << std::endl;

	std::cout << "test 2 divisione" << std::endl;
	BigInteger a("21742178472138971249812481241921247129417284184124719417471");
	BigInteger e("5");
	std::cout << a << "/" << e << "=" << std::endl;
	a /= e;
	std::cout << a << std::endl;
	std::cout << a << "*" << e << "=" << std::endl;
	a *= e;
	std::cout << a << std::endl << std::endl;

	std::cout << "test 3 divisione" << std::endl;
	BigInteger div1("22873424823489300000000000000000000000000000000000000000000000001212343254789562228734248234893000000000000000000000000000000000000000000000000012123432547895622287342482348930000000000000000000000000000000000000000000000000121234325478956222873424823489300000000000000000000000000000000000000000000000001212343254789562");
	BigInteger div2("228734240000000000000000000000000000000000000012123432547895622287342482348930000000000000000000000000000000000000000000000000121234325478956222873424823489300000000000000000000000000000000000000000000000001212343254789562");
	std::cout << div1 << " / " << div2 << "=" << std::endl;
	std::cout << div1 / div2 << std::endl;

	std::cout << std::endl << "***test radice n-esima***" << std::endl;

	BigInteger rad2("429981696");
	std::cout << "radice 8 di " << rad2 << std::endl;
	std::cout << "risultato approssimato: " << radix(rad2, 8, 10) << std::endl;

	std::cout << std::endl << "***test potenza intera e bigint***" << std::endl;
	std::cout << a << " ^ 500: " << std::endl;
	BigInteger acopy(a);
	BigInteger pow(500);
	a.pow(pow);
	acopy.pow(500);

	//too long to print...
	//std::cout<<acopy<<std::endl;
	//std::cout<<a<<std::endl;

	if (a == acopy)
		std::cout << "potenza per intero e per bigint coincidenti" << std::endl;
	else
		std::cout << "non coincidono" << std::endl;

	BigInteger aie("20000000000");
	BigInteger bie("10");

	for (int i = 0; i<5000; i++)
		aie *= bie;

	tempofinale = clock();
	double tempo = ((float)tempofinale - tempoiniziale) / CLOCKS_PER_SEC;
	std::cout << std::endl << "ms: " << tempo;
	int k;
	std::cin >> k;
}
#endif
