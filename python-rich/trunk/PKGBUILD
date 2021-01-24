# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=9.9.0
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-setuptools' 'python-dephell')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('194bba8254750aa5776540d7153090d748d2dc596be434e1c036949164a892c728c88eaf83d56a70d1cc770175167ac3a10a9af2aec3bd477f7aebaa272c8855')

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
