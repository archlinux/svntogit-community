# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Andrey Mikhaylenko <neithere at gmail dot com>

pkgname=python-argcomplete
_pyname=argcomplete
pkgver=1.10.0
_gitcommit=9d6dd18ae402b606bbd7d0fea663971fc7e42e97
pkgrel=3
pkgdesc='Easy, extensible command line tab completion of arguments for your Python script'
url='https://github.com/kislyuk/argcomplete'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('git' 'python-setuptools')
checkdepends=('python-pexpect' 'tcsh' 'fish')
source=(${_pyname}::"git+https://github.com/kislyuk/${_pyname}#commit=${_gitcommit}?signed")
sha512sums=('SKIP')
validpgpkeys=('29BCBADB4ECAAAC2382699388AFAFCD242818A52') # Andrey Kislyuk <kislyuk@gmail.com>

pkgver() {
  cd ${_pyname}
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

build() {
  cd ${_pyname}
  python setup.py build
}

check() {
  cd ${_pyname}
  LC_CTYPE=en_US.UTF-8 python test/test.py -v
}

package() {
  cd ${_pyname}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
}

# vim: ts=2 sw=2 et:
