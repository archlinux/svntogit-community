# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

_name=Nuitka
pkgname=nuitka
pkgver=0.6.15.3
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=('any')
url='https://nuitka.net/'
license=('Apache')
depends=('python-appdirs' 'scons')
makedepends=('python-setuptools')
checkdepends=('ccache' 'fuse2' 'python-boto3' 'python-brotli' 'strace')
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('457a4adc116e41b288e8ec43ac5413cd1b712c5abddfc585d64e6ac25bd702ea75bbeef3418a10d1fdf7940ad868184a1befb9d90ad8dcd08b2b466c03d4a560')
b2sums=('3790b20be3d9a0fae6649ebc95b8faed517551943d5ea092407cd3baf76cddb248a892c436544a3bfc05800675ac739e978b9f11e6c8d918ed982d113ed4a53f')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
}

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${pkgname}-${pkgver}"
  # skip tests for other interpreters and those that require network access
  ./tests/run-tests --no-other-python --skip-reflection-test --skip-other-cpython-tests --skip-onefile-tests
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --skip-build \
                          --optimize=1 \
                          --root="${pkgdir}"
  install -vDm 644 {Changelog,Developer_Manual,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}/"
}
