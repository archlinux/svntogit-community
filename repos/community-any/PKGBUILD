# Submitter: Simon Conseil <contact+aur at saimon dot org>
# Submitter: Jesus Alvarez
# Maintainer: Danilo Bargen <gezuru@gmail.com>

pkgbase=python-jedi
pkgname=('python2-jedi' 'python-jedi')
pkgver=0.7.0
pkgrel=3
arch=('any')
url="https://github.com/davidhalter/jedi"
license=('LGPL3')
depends=('python2')
makedepends=('python2-distribute' 'python-distribute')
source=("https://pypi.python.org/packages/source/j/jedi/jedi-${pkgver}.tar.gz")
sha256sums=('01f0d070ff3852bb6325f436c87070714ccf3d6edb057d9b562a1b19a601daa9')

build() {
   cd "$srcdir/jedi-$pkgver" 
}

package_python-jedi() {
    pkgdesc="Awesome autocompletion for python"
    depends=('python')
    conflicts=('python3-jedi-git')
    cd "$srcdir/jedi-$pkgver"
    python3 setup.py install --root="$pkgdir/" --optimize=1
}

package_python2-jedi() {
    pkgdesc="Awesome autocompletion for python2"
    depends=('python2')
    conflicts=('jedi-git' 'python2-jedi-git')
    cd "$srcdir/jedi-$pkgver"
    python2 setup.py install --root="$pkgdir/" --optimize=1
}

# vim:set ts=2 sw=2 et
