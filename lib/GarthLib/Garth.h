////////////////////////////////////////
////////////////////////////////////////
//
//	Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file Garth.h
//
//  Description:
//      \brief Garth Library header.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Include guards:
#ifndef GARTH_H
#define GARTH_H


// Forward declarations:
////


// Local includes:
////


// Compiler includes:
////


/// Garth namespace
namespace Garth
{

	/// GarthEngine class
	class GarthEngine
	{
		private:
			char status;

		public:
			void start();
			void pause();
			void stop();
	};

} // Garth namespace


#endif // GARTH_H
