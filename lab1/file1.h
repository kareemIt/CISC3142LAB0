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
