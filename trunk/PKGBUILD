# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=fira-mono
pkgname=(ttf-fira-mono otf-fira-mono)
pkgver=3.206
_tag=4.106  # Tags are at Fira Sans' version
pkgrel=4
epoch=2
pkgdesc="Mozilla's typeface designed for Firefox OS (Monospace)"
arch=('any')
license=('custom:OFL')
url='https://github.com/mozilla/Fira'
source=("$pkgbase-$pkgver.tar.gz::https://github.com/mozilla/Fira/archive/$_tag.tar.gz")
sha512sums=('e8ad42351065f6a9308c5a7315f126886d243a6789425507a381a1d31443cd1aa8d981d04956bd2f2d0a193a9f3f7bc7d94cfec4b5dcfb0389d7d963295686d3')

function _package {
    cd Fira-$_tag

    case "$1" in
        ttf-fira-mono)
            pkgdesc="Mozilla's monospace typeface designed for Firefox OS"
            cd ttf
            fonts=(FiraMono*.ttf)
            installdir=TTF;;
        otf-fira-mono)
            pkgdesc="Mozilla's monospace typeface designed for Firefox OS"
            cd otf
            fonts=(FiraMono*.otf)
            installdir=OTF;;
    esac

    # Prepare destination directory
    install -dm755 "$pkgdir/usr/share/fonts/$installdir"

    # Install fonts
    for font in "${fonts[@]}"; do
        install -m644 "$font" "$pkgdir/usr/share/fonts/$installdir"
    done

    install -D -m644 ../LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"   
}

for _pkgname in ${pkgname[@]}; do
    eval "function package_$_pkgname() { _package $_pkgname; }"
done
