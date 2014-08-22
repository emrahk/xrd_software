/*
 * rena.cpp
 *
 *  Created on: 05 Þub 2014
 *      Author: Asus
 */

#include "rena.h"

namespace MSP430
{

rena::rena()
{
	// TODO Auto-generated constructor stub

}

void rena::ConfigureRena(channelconfig* config, unsigned char channelcount, pulsar cin, pulsar cshift, pulsar cs)
{
	cin.set(0);
	cshift.set(0);
	//cs.set(1);

	//delay


	//delay

	for(unsigned char i=0;i<channelcount;i++)
	{
		cs.set(0);

		for(unsigned char adr=0;adr<6;adr++)
		{
			cin.set((config[i].address & ( 32 >> adr)) );
			//delay
			cshift.set(1);
			//delay
			cshift.set(0);
			//delay
		}

		cin.set(config[i].FB_TC);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay


		cin.set(config[i].ECAL);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay


		cin.set(config[i].FPDWN);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay


		cin.set(config[i].FETSEL);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay

		for(unsigned char gs=0;gs<2;gs++)
		{
			cin.set(config[i].gainselect & ( 2 >> gs));
			//delay
			cshift.set(1);
			//delay
			cshift.set(0);
			//delay
		}

		cin.set(config[i].PDWN);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay


		cin.set(config[i].PZSEL);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay


		cin.set(config[i].RANGE);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay


		cin.set(config[i].RSEL);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay

		for(unsigned char sl = 0; sl < 4; sl++)
		{

			cin.set((config[i].SEL & (8 >> sl)));
			//delay
			cshift.set(1);
			//delay
			cshift.set(0);
			//delay

		}

		cin.set(config[i].SIZEA);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay

		for(unsigned char df = 0; df < 8; df++)
		{
			cin.set(config[i].DF & (128 >> df));
			//delay
			cshift.set(1);
			//delay
			cshift.set(0);
			//delay
		}

		cin.set(config[i].POL);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay

		for(unsigned char ds = 0; ds < 8; ds++)
		{
			cin.set(config[i].DS & (128 >> ds));
			//delay
			cshift.set(1);
			//delay
			cshift.set(0);
			//delay
		}

		cin.set(config[i].ENF);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay

		cin.set(config[i].ENS);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay

		cin.set(config[i].FM);
		//delay
		cshift.set(1);
		//delay
		cshift.set(0);
		//delay

		//delay(10);
		cs.set(1);
		delay(200); //Dikkat!
	}


	//delay

}

unsigned char rena::CheckRENAConfig()
{
	return 1;
}

unsigned char rena::StandardPeakDetectionSequance(pulsar acq, pulsar cls, pulsar ts, unsigned int clspulsewidth, unsigned int traptime, unsigned int timoutdelay, unsigned int acqdelay)
{
	cls.set(1);
	delay(clspulsewidth);
	acq.set(1);
	cls.set(0);

	//early trigger control

	/*while(traptime--)
	{
		delay(1);
		if()
	}*/


	return 1;
}


} /* namespace msp430 */
