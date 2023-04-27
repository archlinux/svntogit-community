# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=13.3.5
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=(python-{colorama,markdown-it-py,pygments})
makedepends=(python-{build,installer,poetry-core,wheel})
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('5bc7f3571dfdbbe50dbdc7c6a5b55073e84b780e65f5a5bc6c8611e9b6b400ceee4ed52d16bdc4221b6ab9259a730b538fad023b6bb3c6269a526ce5d663ee7f')

build() {
  cd rich-${pkgver}
  python -m build --wheel --no-isolation
}

package() {
  cd rich-${pkgver}
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
