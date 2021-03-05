// File: points2d
// Author: Rabiul Mazumder
// Description: Points2D is a class that describes a sequence of 2D points aka points in a 2D-plane
// Date: Feb 23, 2021

#ifndef CSCI335_HOMEWORK2_POINTS2D_H_
#define CSCI335_HOMEWORK2_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
	// Place comments that provide a brief explanation of this class,
	// and its sample usage.
	template<typename Object>
	class Points2D {
	public:
		// Default "big five" -- you have to alter them for your assignment.
		// That means that you will remove the "= default" statement.
		//  and you will provide an implementation for it.

		// Zero-parameter constructor. 
		// Set size to 0.
		Points2D() {
			size_ = 0;
			sequence_ = nullptr;
		};

		// Copy-constructor.
		Points2D(const Points2D &rhs) {
			size_ = rhs.size_;
			sequence_ = new std::array<Object, 2>[size_]; // this creates a new array with the input size
			for (size_t i = 0; i < size_; ++i) {
				sequence_[i] = std::array<Object, 2>{ {rhs.sequence_[i][0], rhs.sequence_[i][1]}}; //copies the element
			}
		}

		// Copy-assignment. If you have already written
		// the copy-constructor and the move-constructor
		// you can just use:
		// {
		// Points2D copy = rhs; 
		// std::swap(*this, copy);
		// return *this;
		// }
		Points2D& operator=(const Points2D &rhs) { //Used given due to having the copy-constructor and the move-constructor
			Points2D copy = rhs;
			std::swap(*this, copy);
			return *this;
		}

		// Move-constructor. 
		Points2D(Points2D &&rhs) {
			size_ = rhs.size_;
			sequence_ = rhs.sequence_;
			rhs.sequence_ = nullptr;
			rhs.size_ = 0;
		}

		// Move-assignment.
		// Just use std::swap() for all variables.
		Points2D& operator=(Points2D &&rhs) {
			std::swap(sequence_, rhs.sequence_);
			std::swap(size_, rhs.size_);
			return rhs;
		}

		// Destructor 
		~Points2D() = default;

		// End of big-five.

		// One parameter constructor.
		Points2D(const std::array<Object, 2>& item) {
			sequence_ = new std::array<Object, 2>(item);
			size_ = 1;
		}

		// Read a chain from standard input.
		void ReadPoints2D() {
			// Part of code included (without error checking).
			std::string input_line;
			std::getline(std::cin, input_line);
			std::stringstream input_stream(input_line);
			if (input_line.empty()) return;
			// Read size of sequence (an integer).
			int size_of_sequence;
			input_stream >> size_of_sequence;
			// Allocate space for sequence.
			delete[] sequence_;
			sequence_ = new std::array<Object, 2>[size_of_sequence];
			size_ = size_of_sequence;

			Object token;
			Object token_2;
			for (int i = 0; input_stream >> token; ++i) {
				input_stream >> token_2;
				// Read coordinates.
				sequence_[i] = std::array<Object, 2>{ {token, token_2}};
			}
		}

    // This just returns the size of the sequence
		size_t size() const {
			return size_;
		}

		// @location: an index to a location in the given sequence.
		// @returns the point at @location.
		// const version.
		// abort() if out-of-range.
		const std::array<Object, 2>& operator[](size_t location) const {
			if (location >0 || location < size_) {
				return sequence_[location];
			}
			else {
				std::abort();
			}
		}

		//  @c1: A sequence.
		//  @c2: A second sequence.
		//  @return their sum. If the sequences are not of the same size, append the
		//    result with the remaining part of the larger sequence.
		friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
			Points2D results;

			int big;
			int small;
			Points2D append;

      // When size of the first sequence is lesser than or equal to the  size of the second sequence
      // small is the size of the first sequence
      // big is the size of the second sequence
      // append is set to the largest sequence
			if (c1.size_ <= c2.size_) {
				small = c1.size_;
				big = c2.size_;
        append = c2;
			}

      // small is the size of the second sequence
      // big is the size of the first sequence
      // append is set to the largest sequence
			else {
				small = c2.size_;
				big = c1.size_;
				append = c1;
			}

      // copies the big size and create a new sequence
			results.size_ = big;
			results.sequence_ = new std::array<Object, 2>[big];

      // adds x values and y values to the sequence
			for (int i = 0; i < small; i++) {
				results.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
				results.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
			}

      // appends the results
			for (int i = small; i < big; i++) {
				results.sequence_[i][0] = append.sequence_[i][0];
				results.sequence_[i][1] = append.sequence_[i][1];
			}

			return results;
		}

		// Overloading the << operator.
		friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points2d) {
			// This function only applies when size is equal to zero
      if (some_points2d.size_ == 0) {
				out << "()";
			}

      // Prints out cordinates
			for (size_t i = 0; i < some_points2d.size_; ++i) {
				out << "(" << some_points2d.sequence_[i][0] << ", " << some_points2d.sequence_[i][1] << ") ";
			}

			return out << std::endl;
		}

	private:
		// Sequence of points. 
		std::array<Object, 2> *sequence_;
		// Size of the sequence.
		size_t size_;

	};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK2_POINTS2D_H_