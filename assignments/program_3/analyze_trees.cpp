// opening of the outfile
	outfile.open("analysis.out");

	// opening of the infile
	infile.open("tenthousandwords.txt");

	// initialization of array of strings
	string b[10000];

	//  infile ten thousand words into the array
	for (int m = 0; m < 10000; m++) 
	{
		infile >> b[m];		
	}

	// search the AVL and the BST  for the words
	for (int i = 0; i<10000; i++)
	{
		tree.search(b[i]);
		Atree.search(b[i]);
		
	}
	
	// outfile the output
	outfile << "BST Comparisons = " << tree.retcounts("counter") << endl;
	outfile << "AVL Comparisons = " << Atree.retcounts("counter") << endl;
	outfile <<"Number of Adjectives = " << tree.retcounts("adjective") << endl;
	outfile << "Number of Adverbs = " << tree.retcounts("adverb") << endl;
	outfile << "Number of Nouns = " << tree.retcounts("noun") << endl;
	outfile << "Number of verbs = " << tree.retcounts("verb") << endl;

	// close files
	infile.close();
	outfile.close();

	system("pause");
	return 0;
