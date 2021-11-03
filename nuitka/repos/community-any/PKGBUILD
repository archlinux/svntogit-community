# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.6.17.5
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=(any)
url='https://nuitka.net/'
license=(Apache)
depends=(python-appdirs scons)
makedepends=(python-setuptools)
checkdepends=(ccache fuse2 python-boto3 python-brotli strace)
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables'
            'pyside2: for using Qt5 APIs')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/N/${pkgname^}/${pkgname^}-${pkgver}.tar.gz")
sha512sums=('7ae440504e4367a67a0fa01c5ba2ef5265b612c12f0aa2eb635f4bc3c6447817c7be4792441cec4f32cf55543c43c2f11ee9e72b6b7d2cdf2209e5b6ca2aa7c7')
b2sums=('720b70d47a904c6a5dc34ef70635bc1d113be1368d434d2864715392eab162ccfa8c0f5161f9cecc4da949351ed1974fef212338c09d6f8a5850552ab6c238d6')

prepare() {
  cd ${pkgname^}-$pkgver
  # in our build environment /etc/os-release will not exist, but /usr/lib/os-release will
  sed -e 's|/etc/os-release|/usr/lib/os-release|' -i nuitka/utils/Utils.py
}

build() {
  cd ${pkgname^}-$pkgver
  python setup.py build
}

check() {
  cd ${pkgname^}-$pkgver
  # skip tests for other interpreters and those that require network access
  # NOTE: the test uses "strace", which is currently not supported by the reproducible build system
  ./tests/run-tests --no-other-python --skip-onefile-tests --skip-other-cpython-tests
}

package() {
  cd ${pkgname^}-$pkgver
  python setup.py install --optimize=1 --root="$pkgdir" --skip-build
  install -Dm644 {Changelog,Developer_Manual,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
}
