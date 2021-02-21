# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=9.11.1
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-setuptools' 'python-dephell')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('7dcae32743bfcbbab0af6896f72e865d2a72ab66545168544d065145cf10a2aab4785454e547f011219a85a8aa762f1ed5ebef2b9fb7f44225a2f776835b643d')

prepare() {
  cd rich-${pkgver}
  dephell deps convert --from pyproject.toml --to setup.py
}

build() {
  cd rich-${pkgver}
  python3 setup.py build
}

package() {
  cd rich-${pkgver}
  python3 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
