#include "MagicalContainer.hpp"

namespace ariel
{
    // Constructor
    MagicalContainer::MagicalContainer() : sizeOfContainer(0)
    {
    }
    MagicalContainer::MagicalContainer(const MagicalContainer &other) : sizeOfContainer(other.sizeOfContainer)
    {
        elements = other.elements;
        primes = other.primes;
    }

    MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other)
    {
        if (this != &other)
        {
            sizeOfContainer = other.sizeOfContainer;
            elements = other.elements;
            primes = other.primes;
        }
        return *this;
    }

    MagicalContainer::~MagicalContainer()
    {
        for (auto it = primes.begin(); it != primes.end(); ++it)
        {
            delete *it;
        }
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element)
    {
        sizeOfContainer++;
        elements.insert(std::lower_bound(elements.begin(), elements.end(), element), element);
        if (isPrime(element))
        {
            int *ptr = new int(element);
            auto it = std::lower_bound(primes.begin(), primes.end(), ptr, [](int *a, int *b)
                                       { return *a < *b; });
            primes.insert(it, ptr);
        }
    }
   
    // Remove an element from the container
    void MagicalContainer::removeElement(int element)
    {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) // take o(n) time to find the element to remove
        {
            throw std::runtime_error("Element not found");
        }
        else
        {
            while (std::find(elements.begin(), elements.end(), element) != elements.end()) // take o(n) time to find the element to remove
            {
                sizeOfContainer--;
                elements.erase(std::lower_bound(elements.begin(), elements.end(), element));
                if (isPrime(element))
                { // remove from primes vector
                    for (auto it = primes.begin(); it != primes.end();)
                    {
                        if (**it == element)
                        {
                            // remove from primes
                            delete *it;            // delete the heap-allocated integer
                            it = primes.erase(it); // remove the pointer from the vector
                        }
                        else
                        {
                            ++it;
                        }
                    }
                }
            }
        }
    }

    // Helper function to check if a number is prime
    bool MagicalContainer::isPrime(int num) const
    {
        if (num <= 1)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    // Get the size of the container
    size_t MagicalContainer::size() const
    {
        return sizeOfContainer;
    }

    //--------------------------------------------------AscendingIterator---------------------------------------------

    // AscendingIterator Constructor
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(&container), currentLocationAsc(0)
    {
    }

    // AscendingIterator: Copy Constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), currentLocationAsc(other.currentLocationAsc)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    // AscendingIterator: Assignment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this->container != other.container)
        {
            throw std::runtime_error("Cannot assign iterators of different containers");
        }
        else
        {
            if (this != &other)
            {
                container = other.container;
                currentLocationAsc = other.currentLocationAsc;
            }
        }
        return *this;
    }

    // AscendingIterator: Get the beginning iterator

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator(*container);
    }

    // AscendingIterator: Get the ending iterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator it(*container);
        it.currentLocationAsc = this->container->sizeOfContainer;
        return it;
    }

    // AscendingIterator: Equality operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return container == other.container && currentLocationAsc == other.currentLocationAsc;
    }

    // AscendingIterator: Inequality operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    // AscendingIterator: Greater than operator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return container == other.container && currentLocationAsc > other.currentLocationAsc;
    }

    // AscendingIterator: Less than operator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return container == other.container && currentLocationAsc < other.currentLocationAsc;
    }

    // AscendingIterator: Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const
    {
        return container->elements[currentLocationAsc];
    }

    // AscendingIterator: Pre-increment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (currentLocationAsc >= this->container->sizeOfContainer)
        {
            throw std::runtime_error("Out of range");
        }
        ++currentLocationAsc;
        return *this;
    }

    //----------------------------------End of AscendingIterator---------------------------------------------

    //---------------------------------------SlideCrossIterator---------------------------------------------
    // SideCrossIterator Constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(&container), currentLocationCross(0)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), currentLocationCross(other.currentLocationCross)
    {
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    // SideCrossIterator: Get the beginning iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator(*container);
    }

    // SideCrossIterator: Get the ending iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        SideCrossIterator it(*container);
        it.currentLocationCross = this->container->elements.size();
        return it;
    }

    // SideCrossIterator: Equality operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return container == other.container && currentLocationCross == other.currentLocationCross;
    }

    // SideCrossIterator: Inequality operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    // SideCrossIterator: Greater than operator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return container == other.container && currentLocationCross > other.currentLocationCross;
    }

    // SideCrossIterator: Less than operator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return container == other.container && currentLocationCross < other.currentLocationCross;
    }

    // SideCrossIterator: Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return (*(this->container)).elements[currentLocationCross];
    }

    // SideCrossIterator: Pre-increment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (currentLocationCross >= this->container->elements.size())
        {
            throw std::runtime_error("Out of range");
        }
        if (this->currentLocationCross < (this->container->elements.size() / 2))
        {
            this->currentLocationCross = this->container->sizeOfContainer - this->currentLocationCross - 1;
        }
        else
        {
            if (this->currentLocationCross == (this->container->sizeOfContainer / 2))
            {
                this->currentLocationCross = this->container->sizeOfContainer;
            }
            else
            {
                this->currentLocationCross = this->container->sizeOfContainer - this->currentLocationCross;
            }
        }
        return *this;
    }

    // SideCrossIterator: Assignment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this != &other || this->container != other.container)
        {
            throw std::runtime_error("Out of range");
        }
        else
        {
            if (this != &other)
            {
                this->container = other.container;
                this->currentLocationCross = other.currentLocationCross;
            }
        }
        return *this;
    }

    //----------------------------------End of SideCrossIterator---------------------------------------------

    //---------------------------------------PrimeIterator---------------------------------------------

    // PrimeIterator Constructor
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(&container), currentLocationPrime(0)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), currentLocationPrime(other.currentLocationPrime)
    {
    }

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    // PrimeIterator: Get the beginning iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return *this;
    }

    // PrimeIterator: Get the ending iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        PrimeIterator it(*container);
        it.currentLocationPrime = this->container->primes.size();
        return it;
    }

    // PrimeIterator: Equality operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return container == other.container && currentLocationPrime == other.currentLocationPrime;
    }

    // PrimeIterator: Inequality operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    // PrimeIterator: Greater than operator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return container == other.container && currentLocationPrime > other.currentLocationPrime;
    }

    // PrimeIterator: Less than operator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return container == other.container && currentLocationPrime < other.currentLocationPrime;
    }

    // PrimeIterator: Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const
    {
        return *this->container->primes[currentLocationPrime];
    }

    // PrimeIterator: Pre-increment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (currentLocationPrime >= this->container->primes.size())
        {
            throw std::runtime_error("Out of range");
        }
        ++currentLocationPrime;
        return *this;
    }

    // PrimeIterator: Assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this->container != other.container)
        {
            throw std::runtime_error("Not the same container");
        }
        else if (this != &other)
        {
            this->container = other.container;
            this->currentLocationPrime = other.currentLocationPrime;
        }
        return *this;
    }

    //----------------------------------End of PrimeIterator---------------------------------------------

}
