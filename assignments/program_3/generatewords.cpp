ifstream infile;
	ofstream outfile;

	// opening of files
	outfile.open("tenthousandwords.txt");
	infile.open("word_files/adjectives.txt");

	srand(time(NULL));

	// resizing of vector
	allCat.resize(5);
	if (!infile)
	{
		// error checking
		cout << "file is not open" << endl;
	}
	else
	{
		int i = 0;
		string adj;

		// all adjectives go into the first part of the vector
		while (infile >> adj)
		{
			allCat[0].push_back(adj);
		}

	}
	infile.close();

	infile.open("word_files/adverbs.txt");

	//error checking
	if (!infile)
	{
		cout << "file is not open" << endl;
	}
	else
	{
		string adv;

		// all adverbs go into the second part of the vector
		while (infile >> adv)
		{
			allCat[1].push_back(adv);
		}

	}
	infile.close();
	infile.open("word_files/animals.txt");
	
	if (!infile)
	{
		cout << "file is not open" << endl;
	}
	else
	{
		string animal;

		// all animals go into the third part of the vector
		while (infile >> animal)
		{
			allCat[2].push_back(animal);
		}

	}

	infile.close();
	infile.open("word_files/nouns.txt");
	
	if (!infile)
	{
		cout << "file is not open" << endl;
	}
	else
	{
		string noun;

		// all nouns go into the fourth part of the vector
		while (infile >> noun)
		{
			allCat[3].push_back(noun);
		}

	}

	infile.close();
	infile.open("word_files/verbs.txt");
	
	if (!infile)
	{
		cout << "file is not open" << endl;
	}
	else
	{
		string verb;

		// all verbs go into the fifth part of the vector
		while (infile >> verb)
		{
			allCat[4].push_back(verb);
		}

	}

	infile.close();
	string crazyWord;

	// concatenation of crazy words
	for (int i = 0; i < 10000; i++)
	{
		crazyWord = "";

		// rand used to generate random numbers from 3 to 5
		int nums = (rand() % 3 - 5) * -1;

		for (int i = 0; i < nums - 1; i++)
		{
			// rand function used to generate random numbers from 1 to 5
			int row = rand() % 5;

			// 
			int col = rand() % allCat[row].size();

			crazyWord += allCat[row][col] + " ";

		}

		//pick a noun or animal
		int pick = (rand() % 2) + 2;
		int col = rand() % allCat[pick].size();

		crazyWord += allCat[pick][col];

		// oufile of crazy word
		outfile << crazyWord << endl;
	}

	outfile.close();
