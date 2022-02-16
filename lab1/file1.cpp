// This file shows basic functions of reading in a CSV file using C++98
//Kareem Itani
//The problem given is to read a CSV file then display the average of each brand price, average per catergory.  Then output it to a file, finally for each unique year list the count and then print out the list.

//I read from csv file keep track of the  sku, brand, category, year, price then add them to a map that keeps track of the average price for brand and category.
//Then prints out all the information from the csv, then printed out the information about the brand and the average price, category and the average price.
//Finally print out the all the unique years and skus
//I am using multipe maps that keep track of brand,number of brands,category,number of categories,brand,price averagies of brands,category,price average of categories

/* Homework Objective: fix this program to match the requirements listed:
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{

    // define variables
    string sku, brand, category, year, price;
    vector<int> vSKU;
    vector<string> vBrand;
    vector<string> vCategory;
    vector<int> vYear;
    vector<float> vPrice;

    ifstream in_stream;
    in_stream.open("data.csv"); // opening the file.

    map<string, int> mBrandInv;
    map<string, float> mBrandAvg;

    map<string, int> mCategoryInv;
    map<string, float> mCategoryAvg;

    if (!in_stream.fail())
    { // if the file is open

        string line;
        getline(in_stream, line);
        while (getline(in_stream, line))
        { // while the end of file is NOT reached
            // Fields: sku,brand,category,year,price

            stringstream row(line);
            string stuff;

            getline(row, sku, ',');
            stringstream ssku(sku);
            int iSKU = 0;
            ssku >> iSKU;
            vSKU.push_back(iSKU);

            getline(row, brand, ',');
            stringstream sbrand(brand);
            string sBrand = "";
            sbrand >> sBrand;
            vBrand.push_back(sBrand);

            getline(row, category, ',');
            stringstream scategory(category);
            string sCategory = "";
            scategory >> sCategory;
            vCategory.push_back(sCategory);

            getline(row, year, ',');
            stringstream syear(year);
            int iYear;
            syear >> iYear;
            vYear.push_back(iYear);

            getline(row, price, '\n');
            stringstream sprice(price);
            float fPrice;
            sprice >> fPrice;
            vPrice.push_back(fPrice);

            mBrandAvg[sBrand] += fPrice;
            mBrandInv[sBrand]++;
            mCategoryAvg[sCategory] += fPrice;
            mCategoryInv[sCategory]++; 
        }
    }
    else
    {
        cout << "Unable to open file";
    }

    // output values
    cout << "SKU"
         << "\t"
         << "Brand"
         << "\t"
         << "Cat."
         << "\t"
         << "Year"
         << "\t"
         << "Price"
         << endl;

    for (int j = 0; j < vSKU.size(); j++)
    {
        // Print out SKU, Brand, Category, Year, Price
        cout << vSKU[j] << "\t" << vBrand[j] << "\t" << vCategory[j] << "\t" << vYear[j] << "\t" << vPrice[j] << "\t" << endl;
    }

    // Print out the average price per brand
    cout << "Brand" << "\t" << "Average Price" << endl;
    for (map<string,float>::iterator it = mBrandAvg.begin(); it != mBrandAvg.end(); it++)
    {
        cout << it->first << '\t' << it->second/mBrandInv[it->first] << endl;
    }


  cout << "Category" << "\t" << "Average Price" << endl;
     for (map<string,float>::iterator it = mCategoryAvg.begin(); it != mCategoryAvg.end(); it++)
    {
        cout << it->first << '\t' << it->second/mCategoryInv[it->first] << endl;
    }
    // For each unique year, list the count of skus and also print out the skus as a list
    // Format like so: 2000 (3): 111, 211, 311
    map<int, int> mYearCount;

    for (int i = 0; i < vYear.size(); i++)
    {
        if (mYearCount.find(vYear[i]) == mYearCount.end())
        {
            mYearCount[vYear[i]] = 1;
        }
        else
        {
            mYearCount[vYear[i]]++;
        }
    }

    for (map<int,int>::iterator it = mYearCount.begin(); it != mYearCount.end(); it++)
    {
        cout << it->first << " (" << it->second << "): ";

        for (int i = 0; i < vSKU.size(); i++)
        {
            if (vYear[i] == it->first && it != mYearCount.end())
            {
                cout << vSKU[i] << ", ";
            }
        }

        cout << endl;
    }

    return 0;
}