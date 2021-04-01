    for(int i = 0; i<pair_count; i++){
        int max_index = i;
        int current_strength = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];

        for(int j = 1 + i; j <pair_count; j++){
            int temp_strength = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if(temp_strength > current_strength){
                max_index = j;
                current_strength = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

            }
        }

         pair temp = pairs[max_index];
        pairs[max_index] = pairs[i];
        pairs[i] = temp;
    }











    pair temp;
    
    while(true){
        int swapped = 0;
        
        for(int i = 0; i < pair_count-1; i++){
            if(preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[i+1].winner][pairs[i+1].loser])
            temp.winner = pairs[i].winner;
            temp.loser = pairs[i].loser;
            
            pairs[i].winner = pairs[i+1].winner;
            pairs[i].loser = pairs[i+1].loser;
            
            pairs[i+1].winner = temp.winner;
            pairs[i+1].loser = temp.loser;
            
            swapped++;
        }
        
        if(swapped == 0){
            break;
            
        printf("ye");
        }
    }
    

    return;



   for(int col = 0; col < MAX; col++){
        bool found_source = true;
        
        for(int row = 0; row < MAX; row++){
            if(locked[row][col] == true){
                found_source = false;
                break;
            }
        }
    
        if(found_source){
            printf("k%s\n", candidates[col]);
            return;
        }
    }
    
    return;






a - b = 1 - 0
a - c = 2 - 3
b - c = 2 - 2 






    // TODO
    int pair_index = 0;
    for(int i = 0; i < candidate_count; i++){
        
        for(int j = i + 1; j < candidate_count; j++){
            if(preferences[i][j] - preferences[j][i] > 0){         //if i over j
                pairs[pair_index].winner = i;
                pairs[pair_index].loser = j;
                pair_count++;
            }
            else if(preferences[i][j] - preferences[j][i] < 0){         //if j over i
                pairs[pair_index].winner = j;
                pairs[pair_index].loser = i;
                pair_count++;
            }
        }
    }
    return;





