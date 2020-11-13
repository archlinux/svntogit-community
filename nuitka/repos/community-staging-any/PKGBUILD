# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

_name=Nuitka
pkgname=nuitka
pkgver=0.6.9.6
pkgrel=4
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
sha512sums=('2b1c02ab2f8d798621a3aa03c367c67d352c77e3d33e03feb6945121ea4efc2089724bcf4ef0747fd5dbc3c5b597048287a949baf4ac20979651b4778e697a22')
b2sums=('ef42a68907fe18485b6d2fe597337544147cccc2dc069fbd17adc7268fc0cf18d7bb7deba7437d1ae6a8ecb1ce2702eed70518b4e3d372a4600ecb4a328a2c99')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
  cd "${pkgname}-${pkgver}"
  # upstream CI seems to chmod all files to 700 or 600
  # https://github.com/Nuitka/Nuitka/issues/879
  find "${pkgname}/" *.egg-info/ -type f -exec chmod 644 {} +
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
