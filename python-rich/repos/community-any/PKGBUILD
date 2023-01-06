# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=13.0.1
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=(python-{colorama,commonmark,pygments})
makedepends=(python-{build,installer,poetry-core,wheel})
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('71d6418b483a88834f7fbce9d9ac8deffbf8940b32ac751503b68994ac1717c8cbede57a37fa33ba025ee6f03196a65797f934252c1658e7ca651cef759d731e')

build() {
  cd rich-${pkgver}
  python -m build --wheel --no-isolation
}

package() {
  cd rich-${pkgver}
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
