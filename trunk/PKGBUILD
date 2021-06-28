# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

_name=Nuitka
pkgname=nuitka
pkgver=0.6.16
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
sha512sums=('fd2dcf9a7a9a5269113b07cc5796c7b64ddc22c7f1ee9d88932008cf749647146a9ad6e373368fa8ffbd896349335c869a678657d61929fc4f754d741fb7eaac')
b2sums=('b2962cd353ffa76908f7d791647754a67b4e3718bdbf5178b8f8fb19cb5da4ab12b1c8467131bb0e88804f3b6f0977e4bbe0021c3606fa5bd874c6dcca41e8ae')

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
