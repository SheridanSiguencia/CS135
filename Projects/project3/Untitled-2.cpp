
/*
void Board::pressUp(){

    for(int col = 0; col < numCols; col++)
    {
        vector <int> notZ; 
        for (int row = 0; row < numRows; row++)
        {
            if(panel[row][col] != 0)
                notZ.push_back(panel[row][col]); 
             

        }

       int current = 0; 

       int row = 0; 

       while(current < notZ.size())
       {

            if(current + 1 < notZ.size() && notZ[current] == notZ[current + 1])
            {
                panel[row][col] = notZ[current] * 2; 
                current = current + 2; 

                if((notZ[current]*2)> max)
                    max = notZ[current]*2; 

            }else{

                panel[row][col] = notZ[current]; 
                current += 1; 
            }

            row += 1;
        }

        for(int r = row; r < numRows; r++)
            panel[r][col] = 0; 

    }

    int a, b; 

    selectRandomCell(a, b); 

}

void Board::pressDown(){

    for(int col = 0; col < numCols; col++)
    {
        vector <int> nonZeros; 

        for (int row = numRows - 1; row >= 0; row--)
        {

            if(panel[row][col] != 0)
                nonZeros.push_back(panel[row][col]); 

        }

        int current = 0; 

        int row = numRows - 1; 

        while(current < nonZeros.size())
        {
            if(current + 1 < nonZeros.size() && nonZeros[current] == nonZeros[current + 1])
            {

                panel[row][col] = nonZeros[current] * 2; 

                current += 2; 

                if((nonZeros[current]*2)> max)
                    max = nonZeros[current]*2; 
            }else{

                panel[row][col] = nonZeros[current]; 
                current += 1; 
            }
            row -= 1;
        }

        for(int r = row; r >= 0; r--)
            panel[r][col] = 0; 

    }

    int a; 
    int b; 

    selectRandomCell(a, b); 

}

void Board::pressLeft()
{
    for(int row = 0; row < numRows; row++)
    {

       vector <int> nonZeros; 

       for (int col = 0; col < numCols; col++)
       {
          if(panel[row][col] != 0)
              nonZeros.push_back(panel[row][col]); 
       }

       int current = 0; 
       int col = 0; 

       while(current < nonZeros.size())
       {

           if(current + 1 < nonZeros.size() && nonZeros[current] == nonZeros[current + 1])
            {
                panel[row][col] = nonZeros[current] * 2; 

                current += 3; 

                if((nonZeros[current]*2)> max)
                    max = nonZeros[current]*2; 

            }else{

                panel[row][col] = nonZeros[current]; 

                current += 1; 

            }

            col += 1;

        }

        for(int c = col; c < numCols; c++){

            panel[row][c] = 0; 

        }

    }

    int a; 
    int b; 

    selectRandomCell(a, b); 

}

void Board::pressRight(){

    for(int row = 0; row < numRows; row++)
    {
        vector <int> nonZeros; 

        for (int col = numCols - 1; col >= 0; col--)
        {
            if(panel[row][col] != 0)
                nonZeros.push_back(panel[row][col]); 
        }

        int current = 0; 

        int col = numCols - 1; 

        while(current < nonZeros.size())
        {

            if(current + 1 < nonZeros.size() && nonZeros[current] == nonZeros[current + 1])
            {
                panel[row][col] = nonZeros[current] * 2; 
                current += 2; 

                if((nonZeros[current]*2)> max)
                    max = nonZeros[current]*2; 

            }else{

                panel[row][col] = nonZeros[current]; 
                current = current + 1; 
            }
            
            col-= 1;
        }

        for(int c = col; c >= 0; c--)
            panel[row][c] = 0; 

    }

    int a;
    int b; 

    selectRandomCell(a, b); 

}

if(current + 1 < nonZeros.size() && nonZeros[current] == nonZeros[current + 1])
            {
                panel[row][col] = nonZeros[current] * 2; 

                current += 2; 
*/