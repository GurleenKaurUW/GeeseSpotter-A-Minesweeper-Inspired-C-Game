#include "geesespotter_lib.h"
#include <iostream>

char *create_board(std::size_t x_dim, std::size_t y_dim);

void clean_board(char *board);

void print_board(char *board, std::size_t x_dim, std::size_t y_dim);

void hide_board(char *board, std::size_t x_dim, std::size_t y_dim);

int mark(char *board, std::size_t x_dim, std::size_t y_dim, std::size_t x_loc, std::size_t y_loc);

void compute_neighbours(char *board, std::size_t x_dim, std::size_t y_dim);

bool is_game_won(char *board, std::size_t x_dim, std::size_t y_dim);

int reveal(char *board, std::size_t x_dim, std::size_t y_dim, std::size_t x_loc, std::size_t y_loc);

char *create_board(std::size_t x_dim, std::size_t y_dim){
    std::size_t size_board{x_dim * y_dim};
    char *board = new char[size_board]{};
    for (std::size_t k{0} ; k < size_board ; k++){
        board[k]=0;
    }
    return board;
}

void clean_board(char *board){
    delete[] board;
    board = nullptr;
    return;
}

void print_board(char *board, std::size_t x_dim, std::size_t y_dim){
    for (std::size_t k{0} ; k < x_dim * y_dim ; ++k){
        
        if ((board[k] & 0x10) == 0x10){
            std::cout << 'M' ;
        } else if ((board[k] & 0x20) == 0x20){
            std::cout << '*' ;
        } else {
            int val{board[k]};
            std::cout << val ;
        }
        if ( ((k+1) % x_dim) == 0){
            std::cout << std::endl;
        }
                
    }
    return;
}

void hide_board(char *board, std::size_t x_dim, std::size_t y_dim){
    for (std::size_t k{0} ; k < x_dim * y_dim ; ++k){
        board[k] = board[k] | 0x20 ;
    }
    return;
}

int mark(char *board, std::size_t x_dim, std::size_t y_dim, std::size_t x_loc, std::size_t y_loc){
    
        int k = ( y_loc * x_dim) + x_loc ;
        //revealed
        if ( board[k] & 0x20 != 0x20){        
            return 2;
            
        } else {                              
            //marke the unmarked and unmarks the marked
            board[k] = board[k]  ^ 0x10; 
        }
    
    return 0;
}

void compute_neighbours(char *board, std::size_t x_dim, std::size_t y_dim){
    for (std::size_t k{0} ; k < x_dim*y_dim ; ++k){
        if (board[k] != 9){
            //checking for geese around the corners of the 2d array
            if (k==0){
                int value{0};
                if (board[k+1]==9){
                    value++;
                } if (board[k+x_dim]==9){
                    value++;
                } if (board[k+x_dim+1]==9){
                    value++;
                }
                board[k]=value;
            } 
            if (k==(x_dim - 1)){
                int value{0};
                if (board[k-1]==9){
                    value++;
                } if (board[k+x_dim-1]==9){
                    value++;
                } if (board[k+x_dim]==9){
                    value++;
                }
                board[k]=value;
            } 
            if (k==((x_dim*y_dim)-x_dim)){
                int value{0};
                if (board[k-x_dim]==9){
                    value++;
                } if (board[k-x_dim+1]==9){
                    value++;
                } if (board[k+1]==9){
                    value++;
                }
                board[k]=value;
            } 
            if (k==((x_dim*y_dim)-1)){
                int value{0};
                if (board[k-x_dim]==9){
                    value++;
                } if (board[k-x_dim-1]==9){
                    value++;
                } if (board[k-1]==9){
                    value++;
                }
                board[k]=value;
            }
            //checking for geese around the edges of the 2d array
            if (k>0 && k<(x_dim-1)){
                int value{0};
                if (board[k-1]==9){
                    value++;
                } if (board[k+1]==9){
                    value++;
                } if (board[k+x_dim-1]==9){
                    value++;
                } if (board[k+x_dim]==9){
                    value++;
                } if (board[k+x_dim+1]==9){
                    value++;
                }
                board[k]=value;
            } 
            if (k>=x_dim && k%x_dim==0 && k<=((x_dim*y_dim)-2*x_dim)){
                int value{0};
                if (board[k-x_dim]==9){
                    value++;
                } if (board[k-x_dim+1]==9){
                    value++;
                } if (board[k+1]==9){
                    value++;
                } if (board[k+x_dim]==9){
                    value++;
                } if (board[k+x_dim+1]==9){
                    value++;
                } 
                board[k]=value;
            }   
            if (k>((x_dim*y_dim)-x_dim) && k<((x_dim*y_dim)-1)){
                int value{0};
                if (board[k-1]==9){
                    value++;
                } if (board[k-x_dim-1]==9){
                    value++;
                } if (board[k-x_dim]==9){
                    value++;
                } if (board[k-x_dim+1]==9){
                    value++;
                } if (board[k+1]==9){
                    value++;
                }
                board[k]=value;
            }
            if (k>(x_dim-1) && (k+1)%x_dim==0 && k<((x_dim*y_dim)-1)){
                int value{0};
                if (board[k-x_dim-1]==9){
                    value++;
                } if (board[k-x_dim]==9){
                    value++;
                } if (board[k-1]==9){
                    value++;
                } if (board[k+x_dim-1]==9){
                    value++;
                } if (board[k+x_dim]==9){
                    value++;
                }
                board[k]=value;
            }
            // checking for geese around the centeral co-ordinates of 2s array
            if (k>x_dim && k<((x_dim*y_dim)-x_dim-1) && k%x_dim!=0 && (k+1)%x_dim!=0){
                int value{0};
                if (board[k-x_dim-1]==9){
                    value++;
                } if (board[k-x_dim]==9){
                    value++;
                } if (board[k-x_dim+1]==9){
                    value++;
                } if (board[k-1]==9){
                    value++;
                } if (board[k+1]==9){
                    value++;
                } if (board[k+x_dim-1]==9){
                    value++;
                } if (board[k+x_dim]==9){
                    value++;
                } if (board[k+x_dim+1]==9){
                    value++;
                }
                board[k]=value;
            }
        }
    }
    return;
}
    


bool is_game_won(char *board, std::size_t x_dim, std::size_t y_dim){
    int n_geese{0};
    int revealed_fields{0};
    for (std::size_t k = 0; k<x_dim*y_dim; k++){
        if (board[k] - hidden_mask() == 9 ){
            n_geese++;
        } if ((board[k] - marked_mask() - hidden_mask() ) == 9 ){
            n_geese++;
        } if (board[k] < 9 ){
            revealed_fields++;
        } 
    }
    if ( revealed_fields + n_geese == x_dim*y_dim){
        return true;
    } else {
        return false;
    }
}
 
int reveal(char *board, std::size_t x_dim, std::size_t y_dim, std::size_t x_loc, std::size_t y_loc){
    int k = ( y_loc * x_dim) + x_loc ;
    if ( board[k] < 10){
        return 2;
    } if (( board[k] - hidden_mask() ) < 9 ){
        board[k] = board[k] - hidden_mask();
    } if ( ( board[k] & marked_mask() ) == marked_mask()){
        return 1;
    } if ((board[k] - hidden_mask()) == 9){
        board[k]= board[k] - hidden_mask();
        return 9;
    } if ( board[k] == 0){
        // if 0 is in corner
        if (k==0){
                if ( (board[k+1] & hidden_mask())==hidden_mask()){
                    board[k+1]=board[k+1]-hidden_mask();
                }    
                if ((board[k+x_dim]&hidden_mask())==hidden_mask()){
                    board[k+x_dim]=board[k+x_dim]-hidden_mask();
                } 
                if ((board[k+x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k+x_dim+1]=board[k+1+x_dim]-hidden_mask();
                }
                
        } 
        if (k==(x_dim - 1)){
                if ((board[k-1]&hidden_mask())==hidden_mask()){
                    board[k-1]=board[k-1]-hidden_mask();
                } 
                if ((board[k+x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k+x_dim-1]=board[k+x_dim-1]-hidden_mask();
                } 
                if ((board[k+x_dim]&hidden_mask())==hidden_mask()){
                    board[k+x_dim]=board[k+x_dim]-hidden_mask();
                }
        }
        if (k==((x_dim*y_dim)-x_dim)){
                if ((board[k-x_dim]&hidden_mask())==hidden_mask()){
                    board[k-x_dim]=board[k-x_dim]-hidden_mask();
                } if ((board[k-x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k+1-x_dim]=board[k+1-x_dim]-hidden_mask();
                } if ((board[k+1]&hidden_mask())==hidden_mask()){
                    board[k+1]=board[k+1]-hidden_mask();
                }
        } 
        if (k==((x_dim*y_dim)-1)){
                if ((board[k-x_dim]&hidden_mask())==hidden_mask()){
                    board[k-x_dim]=board[k-x_dim]-hidden_mask();
                } if ((board[k-x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k-x_dim-1]=board[k-x_dim-1]-hidden_mask();
                } if ((board[k-1]&hidden_mask())==hidden_mask()){
                    board[k-1]=board[k-1]-hidden_mask();
                }
        }
        // if 0 is in edges 
        if (k>0 && k<(x_dim-1)){
                if ((board[k-1]&hidden_mask())==hidden_mask()){
                    board[k-1]=board[k-1]-hidden_mask();
                } 
                if ((board[k+1]&hidden_mask())==hidden_mask()){
                    board[k+1]=board[k+1]-hidden_mask();
                } 
                if ((board[k+x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k+x_dim-1]=board[k-1+x_dim]-hidden_mask();
                } 
                if ((board[k+x_dim]&hidden_mask())==hidden_mask()){
                    board[k+x_dim]=board[k+x_dim]-hidden_mask();
                } 
                if ((board[k+x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k+1+x_dim]=board[k+1+x_dim]-hidden_mask();
                }
                
        } 
        if (k>=x_dim && k%x_dim==0 && k<=((x_dim*y_dim)-2*x_dim)){
                
                if ((board[k-x_dim]&hidden_mask())==hidden_mask()){
                    board[k-x_dim]=board[k-x_dim]-hidden_mask();
                }
                if ((board[k-x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k-x_dim+1]=board[k-x_dim+1]-hidden_mask();
                } 
                if ((board[k+1]&hidden_mask())==hidden_mask()){
                    board[k+1]=board[k+1]-hidden_mask();
                } 
                if ((board[k+x_dim]&hidden_mask())==hidden_mask()){
                    board[k+x_dim]=board[k+x_dim]-hidden_mask();
                } 
                if ((board[k+x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k+x_dim+1]=board[k+x_dim+1]-hidden_mask();
                } 
                
        }   
        if (k>((x_dim*y_dim)-x_dim) && k<((x_dim*y_dim)-1)){
                
                if ((board[k-1]&hidden_mask())==hidden_mask()){
                    board[k-1]=board[k-1]-hidden_mask();
                } 
                if ((board[k-x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k-x_dim-1]=board[k-x_dim-1]-hidden_mask();
                } 
                if ((board[k-x_dim]&hidden_mask())==hidden_mask()){
                    board[k-x_dim]=board[k-x_dim]-hidden_mask();
                } 
                if ((board[k-x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k-x_dim+1]=board[k-x_dim+1]-hidden_mask();
                } 
                if ((board[k+1]&hidden_mask())==hidden_mask()){
                    board[k+1]=board[k+1]-hidden_mask();
                }
                
        }
        if (k>(x_dim-1) && (k+1)%x_dim==0 && k<((x_dim*y_dim)-1)){
                
                if ((board[k-x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k-1-x_dim]=board[k-1-x_dim]-hidden_mask();
                } 
                if ((board[k-x_dim]&hidden_mask())==hidden_mask()){
                    board[k-x_dim]=board[k-x_dim]-hidden_mask();
                } 
                if ((board[k-1]&hidden_mask())==hidden_mask()){
                    board[k-1]=board[k-1]-hidden_mask();
                } 
                if ((board[k+x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k-1+x_dim]=board[k-1+x_dim]-hidden_mask();
                } 
                if ((board[k+x_dim]&hidden_mask())==hidden_mask()){
                    board[k+x_dim]=board[k+x_dim]-hidden_mask();
                }
                
        }
        // if 0 is in the middle
        if (k>x_dim && k<((x_dim*y_dim)-x_dim-1) && k%x_dim!=0 && (k+1)%x_dim!=0){
                
                if ((board[k-x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k-1-x_dim]=board[k-1-x_dim]-hidden_mask();
                } 
                if ((board[k-x_dim]&hidden_mask())==hidden_mask()){
                    board[k-x_dim]=board[k-x_dim]-hidden_mask();
                } 
                if ((board[k-x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k-x_dim+1]=board[k-x_dim+1]-hidden_mask();
                } 
                if ((board[k-1]&hidden_mask())==hidden_mask()){
                    board[k-1]=board[k-1]-hidden_mask();
                } 
                if ((board[k+1]&hidden_mask())==hidden_mask()){
                    board[k+1]=board[k+1]-hidden_mask();
                } 
                if ((board[k+x_dim-1]&hidden_mask())==hidden_mask()){
                    board[k-1+x_dim]=board[k-1+x_dim]-hidden_mask();
                } 
                if ((board[k+x_dim]&hidden_mask())==hidden_mask()){
                    board[k+x_dim]=board[k+x_dim]-hidden_mask();
                } 
                if ((board[k+x_dim+1]&hidden_mask())==hidden_mask()){
                    board[k+x_dim+1]=board[k+x_dim+1]-hidden_mask();
                }
        }
    
    }
    return 0;
}