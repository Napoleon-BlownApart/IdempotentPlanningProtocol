#ifndef SIMPLE_SHAPES_H_
#define SIMPLE_SHAPES_H_

#include <cassert>
#include <cstdlib>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <math_fnc.h>
#include <vector>
#include <typeinfo>
//simple shapes classes

#pragma clang diagnostic push
//#pragma clang diagnostic warning "-W#warnings"
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wunused-private-field"

#ifndef SQUARE
#define SQUARE(x) ((x)*(x))
#endif

struct Box {
    int lx;
    int rx;
    int by;
    int ty;
};

struct FieldLine {
	int startX;
	int startY;
	int endX;
	int endY;
	int startThickness;
	int endThickness;
	int length;
	double gradiant;
};

template <class T>
class GUPoint {
public:
        T x, y;
public:
	GUPoint(T x1, T y1): x(x1), y(y1) {}
	GUPoint<T>(): x(0), y(0) {}
	GUPoint(const GUPoint<T> &point): x(point.x), y(point.y) {}
        GUPoint(const char *str): x(0), y(0)    ///< C string constructor
        {                                       //   "(<xvalue>,<yvalue>)"
            if (!str || !*str) return;
            while (*str && *str != '-' && !isdigit(*str)) str++;
            if (!*str) return;
            x = static_cast<T>(atol(str++));

            while (*str && *str != ',') str++;
            if (!*str) return;
            if (!*++str) return;
            y = static_cast<T>(atol(str));
        }

	T Distance(const GUPoint<T> &point) const
        {
		return static_cast<int>(DISTANCE(this->x, this->y, point.x, point.y));
	}

	GUPoint<T> Unit() const
        {
		if(this->x == 0 && this->y == 0)
			return *this;
		else
			return *this / GUPoint::Length(GUPoint<T>(0,0), *this);
	}

	GUPoint UnitFromPoint(const GUPoint<T> &p) const { return (*this - p).Unit(); }

	static inline T Length(const GUPoint<T> &a, const GUPoint<T> &b) 
        {
		return  T(  sqrt(SQUARE(a.x-b.x) + SQUARE(a.y-b.y)) );
	}

	GUPoint<T> operator=(const GUPoint<T> &a)
        {
		this->x = a.x;
		this->y = a.y;
		return *this;
	}
        bool operator==(const GUPoint<T> &a) const
        {
            if(this->x == a.x && this->y == a.y)
                return true;
            return false;
        }
	GUPoint<T> operator*(T a) const { return GUPoint<T>(x*a, y*a); }
	GUPoint<T> operator/(T a) const { return GUPoint<T>(x/a, y/a); }
	GUPoint<T> operator+(const GUPoint<T> &p) const { return GUPoint<T>(x+p.x, y+p.y); }
	GUPoint<T> operator-(const GUPoint<T> &p) const { return GUPoint<T>(x-p.x, y-p.y); }
	GUPoint<short> toShort() const { return GUPoint<short>(short(x), short(y)); }
};

/// super class for other shapes
class SimpleShape {
public:
        SimpleShape() {}
        SimpleShape(const SimpleShape &shape) { shape.Copy(this); }
        SimpleShape &operator=(const SimpleShape &shape) { shape.Copy(this); return *this; }
	virtual short shapePointIntersection(const GUPoint<short> &p, GUPoint<short> *pIntersection) const = 0;
	virtual void Copy(SimpleShape *shape) const = 0;
        virtual bool insideShape(const GUPoint<int> &point) const = 0;
	virtual ~SimpleShape() { }
	virtual int Area() = 0;
	virtual std::vector<GUPoint<short> > intersections(SimpleShape&) { return std::vector<GUPoint<short> >();}
};

class SimpleCircle: public SimpleShape
{
public:
	SimpleCircle(): SimpleShape(), m_dRadius(-1), m_Center(9999, 9999) {}
        SimpleCircle(const SimpleCircle &shape): SimpleShape(shape) {m_dRadius = shape.m_dRadius; m_Center = shape.m_Center;}
        //SimpleCircle(const SimpleShape &shape): SimpleShape(shape) {}
	SimpleCircle(const GUPoint<short> *p1, const GUPoint<short> *p2, const GUPoint<short> *p3) {	// p1, p2, p3 are co-planar
		FindCircle(p1, p2, p3);
	}
        SimpleCircle &operator=(const SimpleCircle &shape) { shape.Copy(this); return *this; }
	virtual short shapePointIntersection(const GUPoint<short> &p, GUPoint<short> *pIntersection) const {
		if(m_dRadius <= 0)
			return -1;
		if(pIntersection != NULL)
			*pIntersection = m_Center + p.UnitFromPoint(m_Center) * short(m_dRadius);
		short len = GUPoint<short>::Length(p, m_Center);
		if(len >= m_dRadius)
			len -= m_dRadius;
		else
			len = short(m_dRadius - len);
		return len;
	}
        virtual bool insideShape(const GUPoint<int> &) const { assert(false); }
	virtual void Copy(SimpleShape *circle) const {
		(static_cast<SimpleCircle *>(circle))->m_Center = this->m_Center;
		(static_cast<SimpleCircle *>(circle))->m_dRadius = this->m_dRadius;
	}
	void FindCircle(const GUPoint<short> *p1, const GUPoint<short> *p2, const GUPoint<short> *p3) {
		this->m_dRadius=-1;		// error checking

		GUPoint<short> pt1=*p1;	GUPoint<short> pt2=*p2;	GUPoint<short> pt3=*p3;

		if (!this->IsPerpendicular(&pt1, &pt2, &pt3) )				this->CalcCircle(&pt1, &pt2, &pt3);
		else if (!this->IsPerpendicular(&pt1, &pt3, &pt2) )		this->CalcCircle(&pt1, &pt3, &pt2);
		else if (!this->IsPerpendicular(&pt2, &pt1, &pt3) )		this->CalcCircle(&pt2, &pt1, &pt3);
		else if (!this->IsPerpendicular(&pt2, &pt3, &pt1) )		this->CalcCircle(&pt2, &pt3, &pt1);
		else if (!this->IsPerpendicular(&pt3, &pt2, &pt1) )		this->CalcCircle(&pt3, &pt2, &pt1);
		else if (!this->IsPerpendicular(&pt3, &pt1, &pt2) )		this->CalcCircle(&pt3, &pt1, &pt2);
		else {
			//The three pts are perpendicular to axis\n
			this->m_dRadius=-1;
		}
	}
	GUPoint<short> GetCenter() const { return m_Center; }
	short GetRadius() const { return short( m_dRadius) ; }
	int Area() {
		return int(PI*GetRadius()*GetRadius());
	}
	void setCenter(GUPoint<short> center) {
		m_Center = center;
	}
	
	void setRadius(double radius) {
		m_dRadius = radius;
	}


private:
	double CalcCircle(GUPoint<short> *pt1, GUPoint<short> *pt2, GUPoint<short> *pt3) {
		double yDelta_a= pt2->y - pt1->y;
		double xDelta_a= pt2->x - pt1->x;
		double yDelta_b= pt3->y - pt2->y;
		double xDelta_b= pt3->x - pt2->x;
		
		if (fabs(xDelta_a) <= 0.000000001 && fabs(yDelta_b) <= 0.000000001){
			this->m_Center.x= short(0.5*(pt2->x + pt3->x));
			this->m_Center.y= short(0.5*(pt1->y + pt2->y));
			this->m_dRadius= GUPoint<short>::Length(this->m_Center, *pt1);// calc. radius
			
			return this->m_dRadius;
		}
		
		// IsPerpendicular() assure that xDelta(s) are not zero
		double aSlope=yDelta_a/xDelta_a; //
		double bSlope=yDelta_b/xDelta_b;
		if (fabs(aSlope-bSlope) <= 0.000000001){	// checking whether the given points are colinear.
			this->m_dRadius = -1;
			return -1;
		}

		double cx, cy, r;
		cx = (aSlope*bSlope*(pt1->y - pt3->y) + bSlope*(pt1->x + pt2 ->x)
			- aSlope*(pt2->x+pt3->x) )/(2.0* (bSlope-aSlope) );
		cy = -1.0*(cx - (pt1->x+pt2->x)/2.0)/aSlope +  (pt1->y+pt2->y)/2.0;
		r = GUPoint<double>::Length(GUPoint<double>(cx, cy), GUPoint<double>(static_cast<double>(pt1->x), static_cast<double>(pt1->y)));
		// calc center
		this->m_Center.x= short(cx + 0.5);
		this->m_Center.y = short(cy + 0.5);
		
		this->m_dRadius= r; // calc. radius

		//fprintf(stderr, "cx %f cy %f r %f\n", cx, cy, r);

		return this->m_dRadius;
	}
	// Check the given point are perpendicular to x or y axis
	bool IsPerpendicular(const GUPoint<short> *pt1, const GUPoint<short> *pt2, const GUPoint<short> *pt3) {
		double yDelta_a= pt2->y - pt1->y;
		double xDelta_a= pt2->x - pt1->x;
		double yDelta_b= pt3->y - pt2->y;
		double xDelta_b= pt3->x - pt2->x;

		// checking whether the line of the two pts are vertical
		if (fabs(xDelta_a) <= 0.000000001 && fabs(yDelta_b) <= 0.000000001){
			return false;
		}

		if (fabs(yDelta_a) <= 0.0000001){
			return true;
		}
		else if (fabs(yDelta_b) <= 0.0000001){
			return true;
		}
		else if (fabs(xDelta_a)<= 0.000000001){
			return true;
		}
		else if (fabs(xDelta_b)<= 0.000000001){
			return true;
		}
		else return false ;
	}
	
	double m_dRadius;
	GUPoint<short> m_Center;
        int32_t _padding;
};

class SimpleLine: public SimpleShape
{
public:
	SimpleLine(): SimpleShape(), start(0, 0), end(0, 0) {}
        SimpleLine(const SimpleLine &line): SimpleShape(), start(line.start), end(line.end) {}
	SimpleLine(const GUPoint<short> *p1, const GUPoint<short> *p2): SimpleShape(), start(*p1), end(*p2) {}
	SimpleLine(const GUPoint<short> &p1, const GUPoint<short> &p2): SimpleShape(), start(p1), end(p2) {}
        SimpleLine &operator=(const SimpleLine &shape) { shape.Copy(this); return *this; }

	short GetLength() const { return GUPoint<short>::Length(start, end); }
	double length() const { return GUPoint<double>::Length(GUPoint<double>(start.x, start.y), GUPoint<double>(end.x, end.y)); }

        virtual bool insideShape(const GUPoint<int> &) const { assert(false); }

	short shapePointIntersection(const GUPoint<short> &p, GUPoint<short> *pIntersection) const
        {
		if(pIntersection != NULL)
                {
                        *pIntersection = dotLineIntersection(p.x, p.y, start.x, start.y, end.x, end.y);
                        return GUPoint<short>::Length(p, *pIntersection);
		}
		else
                {
			double normalLength = sqrt(SQUARE(end.x - start.x) + SQUARE(start.y - end.y));
			return short(abs((p.x - start.x) * (end.y - start.y) - (p.y - start.y)*(end.x - start.x))/normalLength);
		}
	}
	
	int Area() {
		return 0; //TODO, needs four points.
	}
	
	static GUPoint<short> dotLineIntersection(short x, short y, short lx0, short ly0, short lx1, short ly1) {
		if(!(lx1 - lx0))
			return GUPoint<short>(lx0, y);
		else if(!(ly1 - ly0))
			return GUPoint<short>(x, ly0);
		double tg = -1 / ((ly1 - ly0) / static_cast<double>((lx1 - lx0)));
		short left = short((lx1 * (x * tg - y + ly0) + lx0 * (x * - tg + y - ly1)) / (tg * (lx1 - lx0) + ly0 - ly1));
		return GUPoint<short>(left, short(tg * left - tg * x + y));
	}
	
	virtual void Copy(SimpleShape *Line) const
        {
		static_cast<SimpleLine *>(Line)->start = this->start;
		static_cast<SimpleLine *>(Line)->end= this->end;
	}
	
	float Gradiant() const
        {
		if(end.x == start.x)
			return (end.y - start.y)*100;
		return (end.y - start.y)/(end.x - start.x);
	}

	/**
	 * Gives the angle of the line
	 * @return angle between 0 and PI
	 */
	double angle() const {
		if(start.y <= end.y)
			return acos((end.x - start.x)/length());
		else
			return acos((start.x - end.x)/length());
	}
	/**
	 * Extrapolate point on line from given x
     * @param x The x coordinate
     * @return A point that lies on the line with the given x value
     */
	GUPoint<short> pointFromX(short x) {
		short tmpL = static_cast<short>((cos(angle())*(x-start.x)));//length between start and new point
		short y = start.y + static_cast<short>((tmpL*sin(angle())));
		return GUPoint<short>(x, y);
	}
	/**
	 * Extrapolate point on line from given y
     * @param y The y coordinate
     * @return A point that lies on the line with the given y value
     */
	GUPoint<short> pointFromY(short y) {
		int tmpL = static_cast<short>((sin(angle())*(y-start.y)));//length between start and new point
		short x = start.x + static_cast<short>((tmpL*cos(angle())));
		return GUPoint<short>(x, y);
	}
	
	std::vector<GUPoint<short> > intersections(SimpleShape& shape) {
		if(typeid(shape) == typeid(SimpleLine))
			return lineIntersection(static_cast<SimpleLine&>(shape));
		else
			return SimpleShape::intersections(shape);
	}

	
	/**
	 * Calculate the intersection of this line with the given line
     * @param l The line that this line intersects with
     * @return The point of intersection
     */
	std::vector<GUPoint<short> > lineIntersection(SimpleLine& l) const {
		int a1 = end.y - start.y, a2 = l.end.y - l.start.y;
		int b1 = start.x - end.x, b2 = l.start.x - l.end.x;
		int c1 = a1*start.x+b1*start.y, c2 = a2*l.start.x+b2*l.start.y;
		
		std::vector<GUPoint<short> > res;
		
		int det = a1*b2 - a2*b1;
		if(a1*b2 - a2*b1 == 0) {
			return res;
		}
		res.push_back(GUPoint<short>(static_cast<short>((b2*c1-b1*c2)/det), static_cast<short>((a1*c2-a2*c1)/det)));
		
		return res;
	}
	
	/**
	 * Calculates a line normal to the current line that passes through the origin
     * @return The newly calculated line 
     */
	SimpleLine normalToOrigin() const {
		double a = angle();
		if(a >= M_PI_2)
			a-=M_PI_2;
		else 
			a+=M_PI_2;
		SimpleLine normal(GUPoint<short>(0,0), GUPoint<short>(static_cast<short>((cos(a)*100)), static_cast<short>((sin(a)*100))));
		return SimpleLine(GUPoint<short>(0,0), lineIntersection(normal)[0]);
	}

	GUPoint<short> start, end;
};


class SimpleRectangle: public SimpleShape
{
public:
        SimpleRectangle(): SimpleShape(), topLeft(0, 0), bottomRight(0, 0) {}
        SimpleRectangle(const SimpleRectangle &rect): SimpleShape(), topLeft(rect.topLeft), bottomRight(rect.bottomRight) {}
        SimpleRectangle(int left, int right, int top, int bottom)
        {
                int tmp;
                if(left >  right)
                {
                        tmp = right;
                        right = left;
                        left = tmp;
                }
                if(bottom >  top)
                {
                        tmp = bottom;
                        bottom = top;
                        top = tmp;
                }
                topLeft.x = left;
                topLeft.y = top;
                bottomRight.x = right;
                bottomRight.y = bottom;
        }
		
		SimpleRectangle& operator=(const SimpleRectangle& r) {
			topLeft = r.topLeft;
			bottomRight = r.bottomRight;
			return *this;
		}
		
		int Area() {
			return abs(left()-right())*abs(top()-bottom());
		}
    
        virtual void Copy(SimpleShape *rectangle) const
        {
                static_cast<SimpleRectangle *>(rectangle)->bottomRight = bottomRight;
                static_cast<SimpleRectangle *>(rectangle)->topLeft = topLeft;
        }

        virtual short shapePointIntersection(const GUPoint<short> &, GUPoint<short> *) const { assert(false); }

        virtual bool insideShape(const GUPoint<int> &point) const
        {
                return (point.x > topLeft.x && point.x < bottomRight.x) &&
                       (point.y < topLeft.y && point.y > bottomRight.y);
        }
    
        int left() const { return topLeft.x; }
        int right() const { return bottomRight.x; }
        int top() const { return topLeft.y; }
        int bottom() const { return bottomRight.y; }

private:
        GUPoint<int> topLeft, bottomRight;
};

#pragma clang diagnostic pop

#endif
