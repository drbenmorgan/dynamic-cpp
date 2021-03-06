/*
    Copyright (C) 2009, 2011 Ferruccio Barletta (ferruccio.barletta@gmail.com)

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

#include <boost/test/unit_test.hpp>

#include <dynamic/dynamic.hpp>

using namespace dynamic;

static const bool _vba = false, _vbb = true;
static const int _via = 10, _vib = 50;
static const double _vda = 10.0, _vdb  = 50.0;
static const char *_vca = "hello", *_vcb = "world";
static const std::string _vsa = "hello", _vsb = "world";

struct ne_fixture {
    ne_fixture()
        :   vn(),
            vba(_vba), vbb(_vbb),
            via(_via), vib(_vib),
            vda(_vda), vdb(_vdb),
            vca(_vca), vcb(_vcb),
            vsa(_vsa), vsb(_vsb)
    {}


    var vn;
    var vba, vbb;
    var via, vib;
    var vda, vdb;
    var vca, vcb;
    var vsa, vsb;
};

BOOST_FIXTURE_TEST_CASE (relational_ne_null, ne_fixture) {
    BOOST_CHECK(none != _vba);
    BOOST_CHECK(none != _via);
    BOOST_CHECK(none != _vda);
    BOOST_CHECK(none != _vca);
    BOOST_CHECK(none != _vsa);

    BOOST_CHECK(none != vba);
    BOOST_CHECK(none != via);
    BOOST_CHECK(none != vda);
    BOOST_CHECK(none != vca);
    BOOST_CHECK(none != vsa);

    BOOST_CHECK(!(none != none));
}

BOOST_FIXTURE_TEST_CASE (relational_ne_bool, ne_fixture) {
    BOOST_CHECK(vba != vbb);
    BOOST_CHECK(vba != _vbb);

    BOOST_CHECK(vba != via);
    BOOST_CHECK(vba != _via);
    BOOST_CHECK(vba != vda);
    BOOST_CHECK(vba != _vda);
    BOOST_CHECK(vba != vca);
    BOOST_CHECK(vba != _vca);
    BOOST_CHECK(vba != vsa);
    BOOST_CHECK(vba != _vsa);

    BOOST_CHECK(!(vba != _vba));
    BOOST_CHECK(!(vba != vba));
}

BOOST_FIXTURE_TEST_CASE (relational_ne_int, ne_fixture) {
    BOOST_CHECK(via != vib);
    BOOST_CHECK(via != _vib);

    BOOST_CHECK(via != vba);
    BOOST_CHECK(via != _vba);
    BOOST_CHECK(via != vda);
    BOOST_CHECK(via != _vda);
    BOOST_CHECK(via != vca);
    BOOST_CHECK(via != _vca);
    BOOST_CHECK(via != vsa);
    BOOST_CHECK(via != _vsa);

    BOOST_CHECK(!(via != _via));
    BOOST_CHECK(!(via != via));
}

BOOST_FIXTURE_TEST_CASE (relational_ne_double, ne_fixture) {
    BOOST_CHECK(vda != vdb);
    BOOST_CHECK(vda != _vdb);

    BOOST_CHECK(vda != vba);
    BOOST_CHECK(vda != _vba);
    BOOST_CHECK(vda != via);
    BOOST_CHECK(vda != _via);
    BOOST_CHECK(vda != vca);
    BOOST_CHECK(vda != _vca);
    BOOST_CHECK(vda != vsa);
    BOOST_CHECK(vda != _vsa);

    BOOST_CHECK(!(vda != _vda));
    BOOST_CHECK(!(vda != vda));
}

BOOST_FIXTURE_TEST_CASE (relational_ne_string_charp, ne_fixture) {
    BOOST_CHECK(vca != vcb);
    BOOST_CHECK(vca != _vcb);
    BOOST_CHECK(vca != vsb);
    BOOST_CHECK(vca != _vsb);

    BOOST_CHECK(vca != vba);
    BOOST_CHECK(vca != _vba);
    BOOST_CHECK(vca != vda);
    BOOST_CHECK(vca != _vda);
    BOOST_CHECK(vca != via);
    BOOST_CHECK(vca != _via);

    BOOST_CHECK(!(vca != _vca));
    BOOST_CHECK(!(vca != vca));
    BOOST_CHECK(!(vca != _vsa));
    BOOST_CHECK(!(vca != vsa));
}

BOOST_FIXTURE_TEST_CASE (relational_ne_string, ne_fixture) {
    BOOST_CHECK(vsa != vcb);
    BOOST_CHECK(vsa != _vcb);
    BOOST_CHECK(vsa != vsb);
    BOOST_CHECK(vsa != _vsb);

    BOOST_CHECK(vsa != vba);
    BOOST_CHECK(vsa != _vba);
    BOOST_CHECK(vsa != vda);
    BOOST_CHECK(vsa != _vda);
    BOOST_CHECK(vsa != via);
    BOOST_CHECK(vsa != _via);

    BOOST_CHECK(!(vsa != _vca));
    BOOST_CHECK(!(vsa != vca));
    BOOST_CHECK(!(vsa != _vsa));
    BOOST_CHECK(!(vsa != vsa));
}
