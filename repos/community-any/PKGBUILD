# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=9.8.0
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-setuptools' 'python-dephell')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('88a332dbbf6da7ff154b21e466824ad06398124ff65f8bb4caf2b7ad9fc55d2b8ffd605a16a6d6724e6c40f213572c8c88bafb8487002b03d1979f9ef19b4c3d')

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
