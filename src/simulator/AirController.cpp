/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include <list>

AirController::AirController() {
	
	bool busy_route = false;	
}

AirController::~AirController() {
	
}

// Asignacion rutas de espera
void
AirController::WaitRoute(Flight *flights, PointRoute pto1, PointRoute pto2, PointRoute pto3, PointRoute pto4)
{
	flights->setLand(false);	
	flights->getRoute()->clear();	
	flights->getRoute()->push_front(pto1);
	flights->getRoute()->push_front(pto2);
	flights->getRoute()->push_front(pto3);
	flights->getRoute()->push_front(pto4);
}

// Asignación rutas de aterrizaje
void
AirController::LandRoute(Flight *flights, PointRoute pto1, PointRoute pto2, PointRoute pto3, PointRoute pto4)
{
	flights->setLand(true);	
	flights->getRoute()->clear();	
	flights->getRoute()->push_back(pto1);
	flights->getRoute()->push_back(pto2);
	flights->getRoute()->push_back(pto3);
	flights->getRoute()->push_back(pto4);
}

void
AirController::doWork()
{
			std::list<Flight*>flights = Airport::getInstance()->getFlights();	

			std::list<Flight*>::iterator it;

			// Puntos de aterrizaje
			Position pos0(3500.0, 0.0, 100.0);
			Position pos1(0.0, 0.0, 50.0);
			Position pos2(-200.0, 0.0, 25.0);
			Position pos3(-750.0, 0.0, 25.0);

			// Rutas de aterrizaje
			PointRoute pto0, pto1, pto2, pto3;

			pto0.pos = pos0;
			pto0.speed = 600.0;	
			pto1.pos = pos1;
			pto1.speed = 200.0; 
			pto2.pos = pos2;
			pto2.speed = 25.0;	
			pto3.pos = pos3;
			pto3.speed = 15.0;	


			// Puntos de espera a la izquierda
			Position left0(7000.0, -10000.0, 500.0);
			Position left1(11000.0, -10000.0, 500.0);
			Position left2(11000.0, -13000.0, 500.0);
			Position left3(7000.0, -13000.0, 500.0);

			// Rutas de espera a la izquierda
			PointRoute pto0_left, pto1_left, pto2_left, pto3_left;

			pto0_left.pos = left0;
			pto0_left.speed = 300.0;
			pto1_left.pos = left1;
			pto1_left.speed = 300.0;
			pto2_left.pos = left2;
			pto2_left.speed = 300.0;
			pto3_left.pos = left3;
			pto3_left.speed = 300.0;

			// Puntos de espera a la izquierda a gran altitud
			Position left_up0(7000.0, -10000.0, 3000.0);
			Position left_up1(11000.0, -10000.0, 3000.0);
			Position left_up2(11000.0, -13000.0, 3000.0);
			Position left_up3(7000.0, -13000.0, 3000.0);

			// Rutas de espera a la izquierda a gran altitud
			PointRoute pto0_left_up, pto1_left_up, pto2_left_up, pto3_left_up;

			pto0_left_up.pos = left_up0;
			pto0_left_up.speed = 300.0;
			pto1_left_up.pos = left_up1;
			pto1_left_up.speed = 300.0;
			pto2_left_up.pos = left_up2;
			pto2_left_up.speed = 300.0;
			pto3_left_up.pos = left_up3;
			pto3_left_up.speed = 300.0;


			// Puntos de espera a la derecha
			Position right0(7000.0, 10000.0, 500.0);
			Position right1(11000.0, 10000.0, 500.0);
			Position right2(11000.0, 13000.0, 500.0);
			Position right3(7000.0, 13000.0, 500.0);

			// Rutas de espera a la derecha
			PointRoute pto0_right, pto1_right, pto2_right, pto3_right;

			pto0_right.pos = right0;
			pto0_right.speed = 300.0;
			pto1_right.pos = right1;
			pto1_right.speed = 300.0;
			pto2_right.pos = right2;
			pto2_right.speed = 300.0;
			pto3_right.pos = right3;
			pto3_right.speed = 300.0;


			// Puntos de espera a la derecha a gran altitud
			Position right_up0(7000.0, 10000.0, 3000.0);
			Position right_up1(11000.0, 10000.0, 3000.0);
			Position right_up2(11000.0, 13000.0, 3000.0);
			Position right_up3(7000.0, 13000.0, 3000.0);

			// Rutas de espera a la derecha a gran altitud
			PointRoute pto0_right_up, pto1_right_up, pto2_right_up, pto3_right_up;

			pto0_right_up.pos = right_up0;
			pto0_right_up.speed = 300.0;
			pto1_right_up.pos = right_up1;
			pto1_right_up.speed = 300.0;
			pto2_right_up.pos = right_up2;
			pto2_right_up.speed = 300.0;
			pto3_right_up.pos = right_up3;
			pto3_right_up.speed = 300.0;


			// Puntos de espera en el centro
			Position central0(7000.0, -5000.0, 500.0);
			Position central1(11000.0, -2500.0, 500.0);
			Position central2(11000.0, 2500.0, 500.0);
			Position central3(7000.0, 5000.0, 500.0);

			// Rutas de espera en el centro
			PointRoute pto0_central, pto1_central, pto2_central, pto3_central;

			pto0_central.pos = central0;
			pto0_central.speed = 300.0;
			pto1_central.pos = central1;
			pto1_central.speed = 300.0;
			pto2_central.pos = central2;
			pto2_central.speed = 300.0;
			pto3_central.pos = central3;
			pto3_central.speed = 300.0;


			if(!flights.empty()){		

				int cont = 0;	
				int j = 0;
				float distancia = 0;
				it = flights.begin();		

				float mindistancia = (*it)->getPosition().distance(pos3);

				for(it = flights.begin(); it != flights.end(); ++it){
					distancia = (*it)->getPosition().distance(pos3);	

					if(distancia < mindistancia){	

						mindistancia = distancia;	

						cont = j;	
					}
					cont++;
				}
			 	
				bool busy_route = false;	

				for(it = flights.begin(); it != flights.end(); ++it){		

					if((*it)->getLand()){	

						busy_route = true; 	
					}
				}
				if(!busy_route){	

					cont = 0;
					for(it = flights.begin(); cont < j; it++){
						cont++;
					}
					LandRoute(*it, pto0, pto1, pto2, pto3);
				}
				

				float xmin = 5000.0;	
				float ymin = 4000.0; 
				float zmin = 3000.0; 
				for(it = flights.begin(); it != flights.end(); ++it){
						if((*it)->getRoute()->empty()){ 

								if((*it)->getPosition().get_x() >= xmin && (*it)->getPosition().get_y() <= -ymin && (*it)->getPosition().get_z() < zmin){
									WaitRoute(*it, pto0_left, pto1_left, pto2_left, pto3_left);
								}else if((*it)->getPosition().get_x() >= xmin && (*it)->getPosition().get_y() >= ymin && (*it)->getPosition().get_z() < zmin){
									WaitRoute(*it, pto0_right, pto1_right, pto2_right, pto3_right);
								}else if((*it)->getPosition().get_x() >= xmin && (*it)->getPosition().get_y() <= -ymin && (*it)->getPosition().get_z() >= zmin){
									WaitRoute(*it, pto0_left_up, pto1_left_up, pto2_left_up, pto3_left_up);
								}else if((*it)->getPosition().get_x() >= xmin && (*it)->getPosition().get_y() >= ymin && (*it)->getPosition().get_z() >= zmin){
									WaitRoute(*it, pto0_right_up, pto1_right_up, pto2_right_up, pto3_right_up);
								}else{
									WaitRoute(*it, pto0_central, pto1_central, pto2_central, pto3_central);
								}
						}
				}
		}
}
