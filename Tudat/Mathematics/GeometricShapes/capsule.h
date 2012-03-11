/*    Copyright (c) 2010-2012 Delft University of Technology.
 *
 *    This software is protected by national and international copyright.
 *    Any unauthorized use, reproduction or modification is unlawful and
 *    will be prosecuted. Commercial and non-private application of the
 *    software in any form is strictly prohibited unless otherwise granted
 *    by the authors.
 *
 *    The code is provided without any warranty; without even the implied
 *    warranty of merchantibility or fitness for a particular purpose.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      102511    D. Dirkx          First version of file.
 *      110120    D. Dirkx          Finalized for code check.
 *      110208    K. Kumar          Updated file header; corrected Doxygen comments; minor changes.
 *      110209    D. Dirkx          Minor changes.
 *      110209    K. Kumar          Minor changes.
 *      110905    S. Billemont      Reorganized includes.
 *                                  Moved (con/de)structors and getter/setters to header.
 *
 *    References
 *      E.H. Hirschel and C. Weiland, Selected Aerothermodynamic Design Problems
 *      of Hypersonic Flight Vehicles (chapter 5), Springer/AIAA, 2009.
 *
 *      D. Dirkx, Continuous Shape Optimization of Entry Vehicles, MSc thesis,
 *      Delft University of Technology, 2011 (Unpublished).
 *
 */

#ifndef TUDAT_CAPSULE_H
#define TUDAT_CAPSULE_H

#include <iostream>
#include "Tudat/Mathematics/GeometricShapes/compositeSurfaceGeometry.h"

namespace tudat
{

//! Capsule class.
/*!
 * Class that defines a Capsule shape, like that of the Apollo or ARD (Advanced
 * Re-entry Demonstrator) capsule. The class derives from the
 * CompositeSurfaceGeometry class, its constituent surface geometries are
 * a SphereSegment object for the nose region, a ConicalFrustum
 * object for the afterbody, a SphereSegment object for the
 * rear cap, and a Torus object for the connection between the nose and torus
 * parts. The setCapsule( ) function needs to be called after  each of the
 * parameters has been set to initialize the capsule.
 */
class Capsule: public CompositeSurfaceGeometry
{
public:

    //! Default constructor.
    /*!
     * Default constructor, initializes single and composite surface lists.
     */
    Capsule( );

    //! Default destructor.
    /*!
     * Default destructor, deallocates singleSurfaceList's constituent
     * surface geometries.
     */
    ~Capsule( ) { }

    //! Set nose radius.
    /*!
     * Sets the nose radius of the capsule.
     * \param noseRadius Nose radius.
     */
    void setNoseRadius( double noseRadius ) { noseRadius_ = noseRadius; }

    //! Set middle radius.
    /*!
     * Sets the middle radius of the capsule.
     * \param middleRadius middleRadius.
     */
    void setMiddleRadius( double middleRadius ) { middleRadius_ = middleRadius; }

    //! Set rear length.
    /*!
     * Sets the rear length of the capsule.
     * \param rearLength Rear length.
     */
    void setRearLength( double rearLength ) { rearLength_ = rearLength; }

    //! Set rear angle.
    /*!
     * Sets the rear angle of the capsule.
     * \param rearAngle Rear angle.
     */
    void setRearAngle( double rearAngle ) { rearAngle_ = rearAngle; }

    //! Set side radius.
    /*!
     * Sets side radius of the capsule.
     * \param sideRadius Side radius.
     */
    void setSideRadius( double sideRadius ) { sideRadius_ = sideRadius; }

    //! Get nose radius.
    /*!
     * Returns the nose radius of the capsule.
     * \return Nose radius.
     */
    double& getNoseRadius( ) { return noseRadius_; }

    //! Get middle radius.
    /*!
     * Returns the middle radius of the capsule.
     * \return Middle radius.
     */
    double& getMiddleRadius( ) { return middleRadius_; }

    //! Get rear length.
    /*!
     * Returns the rear length of the capsule.
     * \return Rear length.
     */
    double& getRearLength( ) { return rearLength_; }

    //! Get rear angle.
    /*!
     * Returns the rear angle.
     * \return Rear angle.
     */
    double& getRearAngle( ) { return rearAngle_; }

    //! Get side radius.
    /*!
     * Returns the side radius.
     * \return side radius.
     */
    double& getSideRadius( ) { return sideRadius_; }

    //! Create capsule.
    /*!
     * Creates the capsule from parameters. All parameters should have been set
     * before calling this function. This function must be called to  use the
     * capsule.
     */
    void setCapsule( );

    //! Overload ostream to print class information.
    /*!
     * Overloads ostream to print class information, prints the class type,
     * and number defining parameters.
     */
    friend std::ostream &operator<<( std::ostream &stream, Capsule& capsule );

private:

    //! Middle radius.
    /*!
     * Middle radius.
     */
    double middleRadius_;

    //! Nose radius.
    /*!
     * Nose radius.
     */
    double noseRadius_;

    //! Rear length.
    /*!
     * Rear length.
     */
    double rearLength_;

    //! Side radius.
    /*!
     * Side radius.
     */
    double sideRadius_;

    //! Rear angle.
    /*!
     * Rear angle.
     */
    double rearAngle_;
};

} // namespace tudat

#endif // TUDAT_CAPSULE_H