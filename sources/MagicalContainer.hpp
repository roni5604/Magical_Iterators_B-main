#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> elements;
        vector<int*> primes;
        size_t sizeOfContainer;

    public:
        MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        bool isPrime(int num) const;
        size_t size() const;

        class AscendingIterator
        {
        private:
            size_t currentLocationAsc;
            MagicalContainer *container;

        public:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator begin() ;
            AscendingIterator end();
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
            AscendingIterator& operator=(const AscendingIterator& other);
        };

        class SideCrossIterator
        {
        private:
            size_t currentLocationCross;
            MagicalContainer *container;

        public:
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator begin() ;
            SideCrossIterator end();
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();
            SideCrossIterator& operator=(const SideCrossIterator& other);
        };

        class PrimeIterator
        {
            private:
            size_t currentLocationPrime;
            MagicalContainer *container;

            public:
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator begin() ;
            PrimeIterator end();
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();    
            PrimeIterator& operator=(const PrimeIterator& other);        

        };
    };
}


