# Submitter: Simon Conseil <contact+aur at saimon dot org>
# Submitter: Jesus Alvarez
# Maintainer: Danilo Bargen <gezuru@gmail.com>

pkgbase=python-jedi
pkgname=('python2-jedi' 'python-jedi')
pkgver=0.11.0
pkgrel=2
arch=('any')
url="https://github.com/davidhalter/jedi"
license=('MIT')
depends=('python2')
makedepends=('python2-setuptools' 'python-setuptools')
checkdepends=('python-pytest' 'python2-pytest' 'python-parso' 'python2-parso')
source=(https://github.com/davidhalter/jedi/archive/v$pkgver.tar.gz update_requires.patch)
md5sums=('26298afee07465d72dc1fe1091d8ec61'
         'f346f6c86f539492f9eab172e91026f3')

prepare() {
   cd "$srcdir/jedi-${pkgver}"
   # FS#56396
   patch -Np1 -i "${srcdir}/update_requires.patch"
}

check() {
   cd "$srcdir/jedi-${pkgver}"
   pytest test

}

package_python-jedi() {
    pkgdesc="Awesome autocompletion for python"
    depends=('python' 'python-parso')
    conflicts=('python3-jedi-git')
    cd "$srcdir/jedi-${pkgver}"
    python3 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

package_python2-jedi() {
    pkgdesc="Awesome autocompletion for python2"
    depends=('python2' 'python2-parso')
    conflicts=('jedi-git' 'python2-jedi-git')
    cd "$srcdir/jedi-${pkgver}"
    python2 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et
