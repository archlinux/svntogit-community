# Maintainer : Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=0.10
pkgrel=1
pkgdesc="An enhanced Interactive Python shell."
arch=('i686' 'x86_64')
url="http://ipython.scipy.org/"
depends=('python')
optdepends=('wxpython: needed for ipythonx and ipython-wx')
license=('custom')
source=(http://ipython.scipy.org/dist/$pkgname-$pkgver.tar.gz)

build() {
  cd $startdir/src/$pkgname-$pkgver
  mkdir -p $startdir/pkg/usr/share/licenses/ipython/
  install -m644 docs/source/license_and_copyright.txt $startdir/pkg/usr/share/licenses/ipython/license.txt

  python setup.py install --root=$startdir/pkg

  rm -rf $startdir/pkg/usr/share/doc
}
md5sums=('dd10cd1b622c16c1afca2239fcc0dfdf')
