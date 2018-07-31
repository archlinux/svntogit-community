# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Andrey Mikhaylenko <neithere at gmail dot com>

pkgbase=python-argcomplete
pkgname=('python-argcomplete' 'python2-argcomplete')
_pyname=argcomplete
pkgver=1.9.4
pkgrel=2
pkgdesc='Easy, extensible command line tab completion of arguments for your Python script'
url='https://github.com/kislyuk/argcomplete'
arch=('any')
license=('Apache')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pexpect' 'python2-pexpect' 'tcsh')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/kislyuk/${_pyname}/archive/v${pkgver}.tar.gz)
sha256sums=('0ac6fdaa989242e122573eba92976ee9bb27e93cf6f0234324df498ed820f411')
sha512sums=('2b0900b55136739f409c32172933af985f4cdde1c018a4687d02f0c5ecdaf36eb8f960270d16bbd157e79f76992c437ab42fd4c6aa9b6aeb3c7302935bf00970')

prepare() {
  cp -a ${_pyname}-${pkgver}{,-py2}
}

build() {
  (cd ${_pyname}-${pkgver}
    python setup.py build
  )
  (cd ${_pyname}-${pkgver}-py2
    python2 setup.py build
  )
}

check() {
  (cd ${_pyname}-${pkgver}
    LC_CTYPE=en_US.UTF-8 python test/test.py -v
  )
  (cd ${_pyname}-${pkgver}-py2
    LC_CTYPE=en_US.UTF-8 python2 test/test.py -v
  )
}

package_python-argcomplete() {
  depends=('python')

  cd ${_pyname}-${pkgver}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
}

package_python2-argcomplete() {
  depends=('python2')

  cd ${_pyname}-${pkgver}-py2
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
