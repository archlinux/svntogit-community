# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Andrey Mikhaylenko <neithere at gmail dot com>

pkgbase=python-argcomplete
pkgname=('python-argcomplete' 'python2-argcomplete')
_pyname=argcomplete
pkgver=1.10.0
_gitcommit=9d6dd18ae402b606bbd7d0fea663971fc7e42e97
pkgrel=1
pkgdesc='Easy, extensible command line tab completion of arguments for your Python script'
url='https://github.com/kislyuk/argcomplete'
arch=('any')
license=('Apache')
makedepends=('git' 'python-setuptools' 'python2-setuptools')
checkdepends=('python-pexpect' 'python2-pexpect' 'tcsh' 'fish')
source=(${_pyname}::"git+https://github.com/kislyuk/${_pyname}#commit=${_gitcommit}?signed")
sha512sums=('SKIP')
validpgpkeys=('29BCBADB4ECAAAC2382699388AFAFCD242818A52') # Andrey Kislyuk <kislyuk@gmail.com>

pkgver() {
  cd ${_pyname}
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cp -a ${_pyname}{,-py2}
}

build() {
  (cd ${_pyname}
    python setup.py build
  )
  (cd ${_pyname}-py2
    python2 setup.py build
  )
}

check() {
  (cd ${_pyname}
    LC_CTYPE=en_US.UTF-8 python test/test.py -v
  )
  (cd ${_pyname}-py2
    LC_CTYPE=en_US.UTF-8 python2 test/test.py -v
  )
}

package_python-argcomplete() {
  depends=('python')

  cd ${_pyname}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
}

package_python2-argcomplete() {
  depends=('python2')

  cd ${_pyname}-py2
  python2 setup.py install -O1 --root="${pkgdir}" --skip-build
  mv "${pkgdir}/usr/bin/activate-global-python-argcomplete" \
    "${pkgdir}/usr/bin/activate-global-python2-argcomplete"
  mv "${pkgdir}/usr/bin/python-argcomplete-check-easy-install-script" \
    "${pkgdir}/usr/bin/python2-argcomplete-check-easy-install-script"
  mv "${pkgdir}/usr/bin/register-python-argcomplete" \
    "${pkgdir}/usr/bin/register-python2-argcomplete"
  mv "${pkgdir}/usr/bin/python-argcomplete-tcsh" \
    "${pkgdir}/usr/bin/python2-argcomplete-tcsh"
}

# vim: ts=2 sw=2 et:
