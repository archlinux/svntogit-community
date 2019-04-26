# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Andrey Mikhaylenko <neithere at gmail dot com>

pkgbase=python-argcomplete
pkgname=('python-argcomplete' 'python2-argcomplete')
_pyname=argcomplete
pkgver=1.9.5
pkgrel=1
pkgdesc='Easy, extensible command line tab completion of arguments for your Python script'
url='https://github.com/kislyuk/argcomplete'
arch=('any')
license=('Apache')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pexpect' 'python2-pexpect' 'tcsh')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/kislyuk/${_pyname}/archive/v${pkgver}.tar.gz)
sha256sums=('6b1564e91e1c614158baa8dd7d38bd333d0e2ac2d8f7a6cd2f2ad8a90c8d2aca')
sha512sums=('489ce1b82ee6a36d616d95e936afd39191e8451aa4fa10457ffcb18a586ceed4a7165e46cf1a659c2f9dd7485110d25b35fda6df0f80181de7f46345f70a58ce')

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
