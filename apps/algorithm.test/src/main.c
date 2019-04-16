#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

#include "aqnote_sort.h"
#include "aqnote_linked_list.h"

/*
 * function: test qsort function
 * author: Peng Li<aqnote@aqnote.com>
 * date: 20180130
 */
int comparator( const void*, const void* );

int test_aqnote_linked_list() {
    aqnote_linked_list* head;
    head = aqnote_linked_list_init( 16 );
    printf( "LinkedList print:\n" );
    aqnote_linked_list_print( head );

    printf( "LinkedList invertPrint:\n" );
    aqnote_linked_list_invert_print( head );
    printf( "\n" );

    printf( "LinkedList invert:\n" );
    head = aqnote_linked_list_invert( head );
    aqnote_linked_list_print( head );

    return 0;
}

int test_aqnote_sort( int argc, char** argv ) {
    if ( argc != 2 ) {
        printf( "Usage %s ch \n", argv[ 0 ] );
        return 0;
    }

    char ch = *( argv[ 1 ] );

    int     array[]     = {INT_MIN, 9, 0, 8, 7, 5, 6, 2, 3, 1, 4, INT_MAX};
    int     elementSize = sizeof( array[ 0 ] );
    int     arrayLength = sizeof( array ) / elementSize;
    clock_t begin       = clock();
    switch ( ch ) {
    case 'b':
        aqnote_sort_bubble( array, arrayLength );
        break;
    case 'i':
        aqnote_sort_insert( array, arrayLength );
        break;
    case 's':
        aqnote_sort_select( array, arrayLength );
        break;
    case 'q':
        aqnote_sort_quick( array, arrayLength );
        break;
    default:
        qsort( array, arrayLength, elementSize, comparator );
        break;
    };
    clock_t end     = clock();
    double  between = 1000000.0 * ( end - begin ) / CLOCKS_PER_SEC;
    printf( "sort() cost time: %.2f\n", between );
    for ( int i = 0; i < arrayLength; i++ ) {
        printf( "%d ", array[ i ] );
    }
    printf( "\n" );

    return 0;
}

int main( int argc, char* argv[] ) {
    printf( "================================\n" );
    test_aqnote_linked_list();
    printf( "================================\n" );
    test_aqnote_sort( argc, argv );

    puts( "\n" );

    return 0;
}

/**
 * <0 The element pointed by pa goes before the element pointed by pb
 * =0 The element pointed by pa is equivalent to the element pointed by pb
 * >0 The element pointed by pa goes after the element pointed by pb
 */
int comparator( const void* pa, const void* pb ) {
    int a = *(const int*)pa;
    int b = *(const int*)pb;

    if ( a > b )
        return 1;
    else if ( a < b )
        return -1;
    else
        return 0;
}