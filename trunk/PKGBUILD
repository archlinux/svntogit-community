# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

_name=Nuitka
pkgname=nuitka
pkgver=0.6.11.2
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=('any')
url='https://nuitka.net/'
license=('Apache')
depends=('python-appdirs' 'scons')
makedepends=('python-setuptools')
checkdepends=('ccache' 'python-boto3' 'python-brotli' 'strace')
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('19c72f21474446de279f67672a27f6e81a97213be2f82496c89f61377167f41ced6bcd556a2d53290d860bdcfba4d9b32df6bcae186d03edf6ff38730296e986')
b2sums=('4ce260392f25d4ee1223f3146473601ed36aba7a1fc5c1400523711f8d1239dd1cd801c7579acab0c5834f34a2c6293c3e12a2356f7c1be230d6f22c44a61008')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
}

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${pkgname}-${pkgver}"
  ./tests/run-tests --no-other-python --skip-reflection-test --skip-all-cpython-tests
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --skip-build \
                          --optimize=1 \
                          --root="${pkgdir}"
  install -vDm 644 {Changelog,Developer_Manual,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}/"
}
