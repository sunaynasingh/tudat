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
 *      110208    K. Kumar          Updated file header; corrected Doxygen
 *                                  comments; minor changes to functions.
 *      110209    D. Dirkx          Minor changes.
 *      110209    K. Kumar          Minor changes.
 *      110905    S. Billemont      Reorganized includes.
 *                                  Moved (con/de)structors and getter/setters to header.
 *
 *    References
 *
 */

#ifndef TUDAT_CONICAL_FRUSTUM_H
#define TUDAT_CONICAL_FRUSTUM_H

#include <iostream>
#include <Eigen/Core>
#include "Tudat/Mathematics/GeometricShapes/singleSurfaceGeometry.h"

namespace tudat
{

//! ConicalFrustum class.
/*!
 * Class that defines the conical frustum shape. The independent variables are
 * the fraction of the total length of the frustum and the circumferential
 * angle, respectively. Parameters are the initial radius, the length and the
 * the cone half angle, respectively.
 */
class ConicalFrustum : public SingleSurfaceGeometry
{
public:
    
    //! Default consructor.
    /*!
     *  Default constructor.
     */
    ConicalFrustum( ) : coneHalfAngle_( -0.0 ), startRadius_( -0.0 ), length_( -0.0 )
    { minimumIndependentVariable2_ = 0; maximumIndependentVariable2_ = 1; }

    //! Get surface point on conical frustum.
    /*!
     * Retrieves a surface point in Cartesian coordinates on the
     * conical frustum from values of the two independent variables.
     * Function uses cartesianPositionVector_ member variable. Values of
     * this vector set previous to function call are irrelevant.
     * \param lengthFraction Fraction of the length at which to retrieve the
     *          surface point.
     * \param azimuthAngle Value of the azimuth angle at which to retrieve
     *          the surface point.
     * \return Point on conical frustum in Cartesian coordinates.
     */
    Eigen::VectorXd getSurfacePoint( double lengthFraction, double azimuthAngle );

    //! Get surface derivative on conical frustum.
    /*!
     * Retrieves the derivatives of the surface point with respect to the two
     * independent variables. For powerOfLengthFractionDerivative = 1
     * and powerOfAzimuthDerivative = 2 the function returns:
     * \f[
     *      \frac{ d^{ 3 } ( x, y, z ) } { du * dv^{ 2 } }
     * \f]
     * ( with u and v the length fraction and azimuth angle ).
     * \param lengthFraction Length fraction.
     * \param azimuthAngle Azimuth angle.
     * \param powerOfLengthFractionDerivative Power of derivative with respect
     *          to length fraction.
     * \param powerOfAzimuthAngleDerivative Power of derivative with respect to
     *          azimuth angle.
     * \return Surface derivative on conical frustum.
     */
    Eigen::VectorXd getSurfaceDerivative( double lengthFraction, double azimuthAngle,
                                          int powerOfLengthFractionDerivative,
                                          int powerOfAzimuthAngleDerivative );

    //! Get parameter of conical frustum.
    /*!
     * Retrieves a parameter of the conical frustum.
     * \param index Index of parameter to return ( index = 0: returns cone half
     *          angle; index = 1: returns start radius; index = 2: returns
     *          length ).
     * \return Selected parameter.
     */
    double getParameter( int index );

    //! Set parameter of conical frustum.
    /*!
     * Sets a parameter of the conical frustum.
     * Function uses parameter_ member variable to prevent multiple declarations.
     * \param index Index of parameter to return ( index = 0: sets cone half
     *          angle; index = 1: sets start radius; index = 2: sets length ).
     * \param parameter Value of parameter to set.
     */
    void setParameter( int index, double parameter );

    //! Set cone half angle.
    /*!
     * Sets the cone half angle.
     *  \param coneHalfAngle Cone half angle.
     */
    void setConeHalfAngle( double coneHalfAngle ) { coneHalfAngle_ = coneHalfAngle; }

    //! Set length.
    /*!
     * Sets the length.
     * \param length Cone length.
     */
    void setLength( double length ) { length_ = length; }

    //! Set start radius.
    /*!
     * Sets the start radius.
     * \param startRadius Start radius.
     */
    void setStartRadius( double startRadius ) { startRadius_ = startRadius; }

    //! Set minimum azimuth angle.
    /*!
     * Sets the minimum azimuth angle.
     * \param minimumAzimuthAngle Minimum azimuth angle.
     */
    void setMinimumAzimuthAngle( double minimumAzimuthAngle )
    { setMinimumIndependentVariable( 1, minimumAzimuthAngle ); }

    //! Set maximum azimuth angle.
    /*!
     * Sets the maximum azimuth angle.
     * \param maximumAzimuthAngle Maximum azimuth angle.
     */
    void setMaximumAzimuthAngle( double maximumAzimuthAngle )
    { setMaximumIndependentVariable( 1, maximumAzimuthAngle ); }

    //! Get cone half angle.
    /*!
     * Returns the cone half angle.
     * \return Cone half angle.
     */
    double& getConeHalfAngle( ) { return coneHalfAngle_; }

    //! Get length.
    /*!
     * Returns the length.
     * \return Cone length.
     */
    double& getLength( ) { return length_; }

    //! Get start radius.
    /*!
     * Returns the start radius.
     * \return Start radius.
     */
    double& getStartRadius( ) { return startRadius_; }

    //! Get minimum azimuth angle.
    /*!
     * Retuns the minimum azimuth angle.
     *  \return Minimum azimuth angle.
     */
    double getMinimumAzimuthAngle( ) { return minimumIndependentVariable1_; }

    //! Get maximum azimuth angle.
    /*!
     * Returns the maximum azimuth angle.
     * \return Maximum azimuth angle.
     */
    double getMaximumAzimuthAngle( ) { return maximumIndependentVariable1_; }

    //! Overload ostream to print class information.
    /*!
     * Overloaded ostream to print class information, prints the class type,
     * the ranges for the azimuth angle, cone half angle, length and the start
     * radius.
     */
    friend std::ostream &operator<<( std::ostream &stream, ConicalFrustum & conicalFrustum );

protected:

private:

    //! Cone half angle.
    /*!
     * Cone half angle.
     */
    double coneHalfAngle_;

    //! Start radius.
    /*!
     * Start radius.
     */
    double startRadius_;

    //!  Cone length.
    /*!
     * Cone length.
     */
    double length_;
};

} // namespace tudat

#endif // TUDAT_CONICAL_FRUSTUM_H