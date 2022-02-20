# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.7
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=(any)
url='https://nuitka.net/'
license=(Apache)
depends=(python-appdirs scons)
makedepends=(python-setuptools)
checkdepends=(ccache fuse2 patchelf python-boto3 python-brotli strace)
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables'
            'pyside2: for using Qt5 APIs')
source=("https://files.pythonhosted.org/packages/source/N/${pkgname^}/${pkgname^}-${pkgver}.tar.gz")
sha512sums=('c097cbb1677caa7ab31f0a4542b57ac110f443a84a7feb44b6e6939599dcbd75e29fb5288861627aee7af6d5ddd2153ea9a8030fc3e9ec2c04b5b34195447925')
b2sums=('265aa830d2230c052a51dd6774f6382ed5fe581a29cf00cbff2b23e6b3e2bb5c49bab35e96584ab519b668fb3ef3a84d3285cd85e561c24bee3afe9ebc78f261')

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
  # skip tests for other interpreters, jinja2 and for those that require network access
  # NOTE: the test uses "strace", which is currently not supported by the reproducible build system
  ./tests/run-tests --no-other-python --skip-onefile-tests --skip-other-cpython-tests --skip-reflection-test
}

package() {
  cd ${pkgname^}-$pkgver
  python setup.py install --optimize=1 --root="$pkgdir" --skip-build
  install -Dm644 {Changelog,Developer_Manual,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
}
